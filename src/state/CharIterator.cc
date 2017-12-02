#include "state/CharIterator.h"

using namespace std;
namespace vm {

// ConstCharIterator implementations ----------------------------------------

ConstCharIterator::ConstCharIterator(const vector<string>& data,
	Pos filePos): data{data}, filePos{filePos} {}

bool ConstCharIterator::operator!=(const ConstCharIterator &other) const {
	return filePos != other.filePos;
}

const char& ConstCharIterator::operator*() const {
	return data[filePos.y][filePos.x];
}

ConstCharIterator ConstCharIterator::operator++(){
  if(filePos.x == data[filePos.y].size() - 1){
    filePos.x = 0;
    filePos.y++;
  }
  else filePos.x++;
	return *this;
}

// CharIterator implementations ----------------------------------------

CharIterator::CharIterator(vector<string>& data, Pos filePos):
	data{data}, filePos{filePos} {}

bool CharIterator::operator!=(const CharIterator &other) const {
	return filePos != other.filePos;
}

char& CharIterator::operator*() const {
	return data[filePos.y][filePos.x];
}

CharIterator CharIterator::operator++(){//TODO wp
  if(filePos.x == data[filePos.y].size() - 1){
    filePos.x = 0;
    filePos.y++;
  }
  else filePos.x++;
	return *this;
}

}
