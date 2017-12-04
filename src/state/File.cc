#include "state/File.h"
#include "state/SyntaxHighlighter.h"
#include <utility>
#include <iostream>

using namespace std;
namespace vm {

File::File(const string& name, vector<string> lines): name{name},
	lines{lines}, cursorPos{Pos{}} {}

File::~File(){}

// LineIterator functions ------------------------------------------------
ConstLineIterator File::MakeLineIterator(size_t y) const {
	return ConstLineIterator(lines, y);
}

ConstLineIterator File::lineBegin() const {
	return ConstLineIterator(lines, 0);
}

ConstLineIterator File::lineEnd() const {
	return ConstLineIterator(lines, lines.size());
}

LineIterator File::MakeLineIterator(size_t y){
	return LineIterator(lines, y);
}

LineIterator File::lineBegin(){
	return LineIterator(lines, 0);
}

LineIterator File::lineEnd(){
	return LineIterator(lines, lines.size());
}

// CharIterator functions -------------------------------------------------

ConstCharIterator File::MakeCharIterator(Pos pos) const {
	return ConstCharIterator(lines, pos);
}

ConstCharIterator File::charBegin() const {
	return ConstCharIterator(lines, Pos(0,0));
}

ConstCharIterator File::charEnd() const {
	return ConstCharIterator(lines, Pos(0,lines.size()));
}

CharIterator File::MakeCharIterator(Pos pos){
	return CharIterator(lines, pos);
}

CharIterator File::charBegin(){
	return CharIterator(lines, Pos(0,0));
}

CharIterator File::charEnd(){
	return CharIterator(lines, Pos(0,lines.size()));
}

// WordIterator functions -------------------------------------------------

ConstWordIterator File::MakeWordIterator(Pos pos) const{
	return ConstWordIterator(lines, pos);
}

ConstWordIterator File::wordBegin() const{
	return ConstWordIterator(lines, Pos(0,0));
}

ConstWordIterator File::wordEnd() const{
	return ConstWordIterator(lines, Pos(lines[lines.size() - 1].size(),lines.size() - 1));
}

// ------------------------------------------------------------------------
const string& File::getName() const {
	return name;
}

string File::getFileExtension() const{
	return name.substr(name.find_last_of(".")+1);
}

string File::getString(Pos start, Pos end) const {
	if(!isValidPos(start) || !isValidPos(end)) throw BadOperationErr{};
	//TODO:
}

const std::vector<string>& File::getLines() const {
	return lines;

}

bool File::isValidPos(Pos p) const {
	return (p.y<lines.size() && p.x < lines[p.y].length());
}

Pos File::getCursorPos() const {
		return cursorPos;
}

Pos File::toScreenCoords(Pos lineCoords) const{
	return Pos{};
	//TODO:
}

Pos File::toLineCoords(Pos screenCoords) const{
	return Pos{};
	//TODO:
}

void File::setCursorPos(Pos p){
	if (!isValidPos(p)) throw BadOperationErr{};
	cursorPos = p;
}

void File::moveCursor(Direction d){

	Pos screen;
	switch (d) {
		case UP: {
			if (cursorPos.y == 0) throw BadOperationErr{};
			screen = toScreenCoords(cursorPos);
			screen.y--;
			setCursorPos(toLineCoords(screen));
			break;
		}
		case DOWN: {
			if (cursorPos.y == lines.size()-1) throw BadOperationErr{};
			Pos screen = toScreenCoords(cursorPos);
			screen.y++;
			setCursorPos(toLineCoords(screen));
			break;
		}
		case LEFT: {
			if (cursorPos.x == 0) throw BadOperationErr{};
			cursorPos.x--;
			break;
		}
		case RIGHT: {
			if (cursorPos.x == lines[cursorPos.y].size()-1) throw BadOperationErr{};
			cursorPos.x++;
			break;
		}
	}
}


void File::addString(string s, Pos pos){
	//TODO:

}

void File::addLines(vector<string> newLines, size_t lineNumber){
	//TODO:
}

void File::replaceString(string s, Pos pos){
	//TODO:
}

void File::replaceLines(vector<string> newLines, size_t lineNumber){
	//TODO:
}

void File::removeString(Pos start, Pos end){
	//TODO:
}

void File::removeLines(size_t start, size_t end){
	//TODO:
}

// difference tracking ----------------------------------------------------

void File::undo(){
}

// Syntax Highlighting ------------------------------------------------------

const IndicatorPack& File::getIndicatorPack() const{
	return indicatorPack;
}

IndicatorPack& File::getIndicatorPack(){
	return indicatorPack;
}

void File::parseAttributes(){
	if(syntaxHighlighter == nullptr) return;

	indicatorPack.rangeIndicators.clear();
	indicatorPack.wordIndicators.clear();

	// Parse range attributes
	size_t linePos = 0;
	int lookingForEnd = -1;

	std::vector<std::pair<Pos, int> > rangeIndicators;

	//make pairs of switchpoints with syntax numbers
	for(auto line = lineBegin(); line != lineEnd(); ++line){
	size_t linePos = 0;

		while(linePos < (*line).size()){
			if(lookingForEnd == -1){
				//Looking for a range start, pick the first one it encounters
				size_t closestStart = (*line).size();
				std::cout << closestStart << std::endl;
				size_t startIndicatorSize = 0;

				for(auto it = syntaxHighlighter->rangeAttributes.begin(); it != syntaxHighlighter->rangeAttributes.end(); ++it){
					//For each range attribute
					size_t lpos = (*line).find((*it).getStartIndicator(), linePos);
					if(!(lpos == string::npos) && lpos < closestStart){
						lookingForEnd = it->getSyntax();
						closestStart = lpos;
						startIndicatorSize = it->getStartIndicator().size();
					}
				}

				linePos += closestStart + startIndicatorSize;

				//If start point was found, add range indicator
				if(lookingForEnd != -1) rangeIndicators.push_back(std::pair<Pos, int>(Pos(linePos, line.getLineNumber()), lookingForEnd));
			}
			else{
				// Looking for end
				string endIndicator;//TODO move outside

				// Get corresponding end indicator for the start indicator last found
				auto it = syntaxHighlighter->rangeAttributes.begin();
				for(; it != syntaxHighlighter->rangeAttributes.end(); ++it){
					if(it->getSyntax() == lookingForEnd){
						endIndicator = it->getEndIndicator();
						break;
					}
				}

				size_t lpos = (*line).find((*it).getEndIndicator(), linePos);
				// If end indicator is not on line, break loop to continue looking on next line
				if(lpos == string::npos) break;
				else{
					//incremenet line pos, save range indicator, and continue looking for a start indicator.
					linePos+=lpos + endIndicator.size();
					rangeIndicators.push_back(std::pair<Pos, int>(Pos(linePos + endIndicator.size(), line.getLineNumber()), lookingForEnd));
					lookingForEnd = -1;
				}
			}
		}
	}

	indicatorPack.rangeIndicators = rangeIndicators;

//TODO runs
	// Parse word attributes
	for(auto it = syntaxHighlighter->wordAttributes.begin(); it != syntaxHighlighter->wordAttributes.end(); ++it){
		//TODO add determine whitespace function?
		WordIndicator wordIndicator;

		for(auto word = wordBegin(); word != wordEnd(); ++word){ //TODO segfaults in for params
			if((*it)->matches(word)) wordIndicator.words.push_back(std::pair<Pos,  int>(word.getPos(), (*word).size()));
		}
		indicatorPack.wordIndicators.push_back(wordIndicator);
	}
}

void File::setSyntaxHighlighter(const SyntaxHighlighter *s){
	syntaxHighlighter = s;
	//TODO parse when set highlighter?
	//parseAttributes();
	//TODO Uncomment to enable syntaxhighlighting
}

}
