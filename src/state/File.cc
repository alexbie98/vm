#include "File.h"

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



// ------------------------------------------------------------------------
const std::string& File::getName() const {
	return name;
}

const vector<string>& File::getLines() const {
	return lines;
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
