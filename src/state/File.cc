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

const std::vector<string>& File::getLines() const {
	return lines;

}

Pos File::getCursorPos() const {
	return cursorPos;
}

void File::setCursorPos(Pos p){
	if (p.y>=0 && p.y<lines.size() && p.x >=0 && p.x < lines[p.y].length()){
		cursorPos = p;
	}
	else throw BadOperationErr{};
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
