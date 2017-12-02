#include "state/CharIterator.h"

using namespace std;
namespace vm {

// ConstCharIterator implementations ----------------------------------------

ConstCharIterator::ConstCharIterator(const vector<string>& data,
	Pos filePos): data{data}, filePos{filePos} {}

ConstCharIterator::ConstCharIterator(const ConstCharIterator &other):
  data{other.data}, filePos{other.filePos}{}

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

ConstCharIterator ConstCharIterator::minusOne() const{//TODO check
  if(filePos.x == 0 && filePos.y == 0) return ConstCharIterator(data, filePos);
  else if(filePos.x == 0)
    return ConstCharIterator(data, Pos(data[filePos.y - 1].size() - 1, filePos.y - 1));
  else return ConstCharIterator(data, Pos(filePos.x - 1, filePos.y));
}

// CharIterator implementations ----------------------------------------

CharIterator::CharIterator(vector<string>& data, Pos filePos):
	data{data}, filePos{filePos} {}

CharIterator::CharIterator(const CharIterator &other):
  data{other.data}, filePos{other.filePos}{}

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

CharIterator CharIterator::minusOne() const{//TODO check
  if(filePos.x == 0 && filePos.y == 0) return CharIterator(data, filePos);
  else if(filePos.x == 0)
    return CharIterator(data, Pos(data[filePos.y - 1].size() - 1, filePos.y - 1));
  else return CharIterator(data, Pos(filePos.x - 1, filePos.y));
}

}
