#include "state/File.h"
#include "state/SyntaxHighlighter.h"

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
	return ConstCharIterator(lines, Pos(lines[lines.size() - 1].size(),lines.size()));
}

CharIterator File::MakeCharIterator(Pos pos){
	return CharIterator(lines, pos);
}

CharIterator File::charBegin(){
	return CharIterator(lines, Pos(0,0));
}

CharIterator File::charEnd(){
	return CharIterator(lines, Pos(lines[lines.size() - 1].size(),lines.size()));
}

// WordIterator functions -------------------------------------------------

ConstWordIterator File::MakeWordIterator(Pos pos) const{
	return ConstWordIterator(lines, pos);
}

ConstWordIterator File::wordBegin() const{
	return ConstWordIterator(lines, Pos(0,0));
}

ConstWordIterator File::wordEnd() const{
	return ConstWordIterator(lines, Pos(lines[lines.size() - 1].size(),lines.size()));
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
	indicatorPack.rangeIndicators.clear();
	indicatorPack.wordIndicators.clear();

	// Parse range attributes
	for(auto it = syntaxHighlighter->rangeAttributes.begin(); it != syntaxHighlighter->rangeAttributes.end(); ++it){

		size_t linePos = 0;
		bool lookingForStart = true;
		RangeIndicator rangeIndicator;

		for(auto line = lineBegin(); line != lineEnd(); ++line){

			while(linePos <= (*line).size()){
				if(lookingForStart){
					size_t lpos = (*line).find((*it).getStartIndicator(), linePos);
					if(lpos == string::npos) break;
					else{
						linePos+=lpos;
						lookingForStart = false;
						rangeIndicator.ranges.push_back(Pos(lpos, line.getLineNumber()));
					}
				}
				else{ // Looking for end
					size_t lpos = (*line).find((*it).getEndIndicator(), linePos);
					if(lpos == string::npos) break;
					else{
						linePos+=lpos;
						lookingForStart = true;
						rangeIndicator.ranges.push_back(Pos(lpos + (*it).getEndIndicator().size(), line.getLineNumber()));
					}
				}

			}
		}

		indicatorPack.rangeIndicators.push_back(rangeIndicator);
	}

	// Parse word attributes
	for(auto it = syntaxHighlighter->wordAttributes.begin(); it != syntaxHighlighter->wordAttributes.end(); ++it){

		//TODO add determine whitespace function?
		WordIndicator wordIndicator;

		for(auto word = wordBegin(); word != wordEnd(); ++word){
			if((*it)->matches(word)) wordIndicator.words.push_back(word.getPos());
		}

		indicatorPack.wordIndicators.push_back(wordIndicator);
	}
}

void File::setSyntaxHighlighter(const SyntaxHighlighter &s){
	syntaxHighlighter = &s;
}

}
