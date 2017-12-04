#include "state/File.h"
#include "state/SyntaxHighlighter.h"
#include <utility>
#include <iostream>
#include <algorithm>
#include <util/Word.h>

using namespace std;
namespace vm {

File::File(const string& name, vector<string> lines): name{name},
	lines{lines}, cursorPos{Pos{0,0}} {}

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

	if (start.y == end.y){
		return lines[start.y].substr(start.x, end.x-start.x);
	}

	vector<string> chunk{end.y-start.y+1};
	copy(lines.begin()+start.y, lines.begin()+end.y+1, chunk.begin());
	chunk[0] = chunk[0].substr(start.x,string::npos);
	chunk[chunk.size()-1] = chunk[chunk.size()-1].substr(0,end.y);
	
	string s;
	for (const string& line: chunk){
		s+=(line + "\n");
	}
	return s;	
}

const std::vector<string>& File::getLines() const {
	return lines;
}

void File::setCursorPos(Pos p){
	cursorPos = p;
}		

Pos File::getCursorPos() const {
		return cursorPos;
}

Pos File::toScreenCoords(Pos lineCoords) const{
	Pos screenCoords; 
	if(lineCoords.x != string::npos){
		string s = lines[lineCoords.y].substr(0, lineCoords.x+1);
		size_t tabs = count(s.begin(),s.end(), '\t');
		screenCoords.x = tabs*(utils::tabSize-1)+s.length();
	}
	screenCoords.y = lineCoords.y+1;
	return screenCoords;
}

Pos File::toLineCoords(Pos screenCoords) const{
	Pos lineCoords;
	lineCoords.y = screenCoords.y-1;
	for (size_t sum = 0;lineCoords.x <lines[lineCoords.y].size() &&
			sum<screenCoords.x; lineCoords.x++){
		sum+=utils::getCharWidth(lines[lineCoords.y][lineCoords.x]);
	}
	lineCoords.x--;
	return lineCoords;
}


void File::moveCursor(Direction d){
	Pos screen;
	switch (d) {
		case UP: {
			if (cursorPos.y == 0) throw BadOperationErr{};
			screen = toScreenCoords(cursorPos);
			screen.y--;
			setCursorPos(toLineCoords(screen));
			if (cursorPos.x == string::npos && lines[cursorPos.y].length()>0){
				cursorPos.x++;	
			}
			break;
		}
		case DOWN: {
			if (cursorPos.y == lines.size()-1) throw BadOperationErr{};
			screen = toScreenCoords(cursorPos);
			screen.y++;
			setCursorPos(toLineCoords(screen));
			if (cursorPos.x == string::npos && lines[cursorPos.y].length()>0){
				cursorPos.x++;	
			}
			break;
		}
		case LEFT: {
			if (cursorPos.x==0 || cursorPos.x == string::npos) throw BadOperationErr{};
			cursorPos.x--;
			break;
		}
		case RIGHT: {
			if (cursorPos.x == lines[cursorPos.y].size()-1) throw BadOperationErr{};
			cursorPos.x++;
			break;
		}
	}
	cout << cursorPos.x << " " << cursorPos.y << endl;
	//line = toLineCoords(cursorPos);
	//cout << line.x <<" "<<line.y<< endl;
}


void File::addString(string s, Pos pos){
	
	while(!s.empty()){
		size_t nextNewLine = s.find("\n");
		if (nextNewLine == 0){
			pos.y++;
			lines.insert(lines.begin()+pos.y, string{});
		}
		else {
			string add = lines[pos.y].insert(pos.x+1,s.substr(0,nextNewLine));
			pos.x+=add.size();
			s = s.substr(nextNewLine);
		}
	}		
}

void File::addLines(vector<string> newLines, size_t lineNumber){
	lines.insert(lines.begin()+lineNumber+1,newLines.begin(), newLines.end());
}

// NO NEWLINES
void File::replaceString(string s, Pos pos){
	for (size_t i = pos.x;i<s.length();i++){
		lines[pos.y][i] = s[i-pos.x];
	}
}

void File::replaceLines(vector<string> newLines, size_t lineNumber){
	for (size_t i = lineNumber;i<newLines.size();i++){
		if (i<lines.size()){
			lines[i] = newLines[i-lineNumber];
		}
		else{
			lines.push_back(newLines[i-lineNumber]);
		}
	}	
}

void File::removeString(Pos start, Pos end){
	if (end.y < start.y || (end.y == start.y && end.x < start.x)){
		swap(start,end);
	}
	string before = lines[start.y].substr(0,start.x);
	string after = lines[end.y].substr(end.x, string::npos);
	lines[start.y] = before + after;
	lines.erase(lines.begin()+start.y+1, lines.begin()+end.y+1);
}

void File::removeLines(size_t start, size_t end){
	lines.erase(lines.begin()+start, lines.begin()+end+1);
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
