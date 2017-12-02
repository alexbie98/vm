#include "state/File.h"

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



// ------------------------------------------------------------------------
const string& File::getName() const {
	return name;
}

string File::getString(Pos start, Pos end) const {
	return "";
}

const std::vector<string>& File::getLines() const {
	return lines;

}

Pos File::getCursorPos() const {
		return cursorPos;
}

Pos File::toScreenCoords(Pos lineCoords) const{
	return Pos{};
}

Pos File::toLineCoords(Pos screenCoords) const{
	return Pos{};
}

void File::setCursorPos(Pos p){
	if (p.y<lines.size() && p.x < lines[p.y].length()){
		cursorPos = p;
	}
	else throw BadOperationErr{};
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
  //TODO
}

void File::addLines(vector<string> newLines, size_t lineNumber){
  //TODO
}

void File::replaceString(string s, Pos pos){
  //TODO
}

void File::replaceLines(vector<string> newLines, size_t lineNumber){
  //TODO
}

void File::removeString(Pos start, Pos end){
  //TODO
}

void File::removeLines(size_t start, size_t end){
  //TODO
}

void File::undo(){
  //TODO
}

}
