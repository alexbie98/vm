#include "state/WordIterator.h"

using namespace std;
namespace vm {

// ConstWordIterator implementations ----------------------------------------

ConstWordIterator::ConstWordIterator(const vector<string>& data,
	Pos filePos): it{data, filePos},
                fileEnd{ConstCharIterator(data, Pos(data[data.size() - 1].size(),data.size()))}{
      if(it.filePos.x == 0){
        while(*it <= 32 && it != fileEnd) ++it; //is whitespace
      }
      else if(!(*(it.minusOne()) <= 32)){
        while(*it <= 32 && it != fileEnd) ++it;
      }

      // "it" should now point to either the first space in the file,
      // the last space in the file, or the first character of the first
      // word in file after filePos.
      //TODO check
  }

bool ConstWordIterator::operator!=(const ConstWordIterator &other) const {
	return it != other.it;
}

std::string ConstWordIterator::operator*() const { //TODO return substring ref?
  size_t substringSize = 0;
  ConstCharIterator jt(it);
  size_t currentY = jt.filePos.y;
  while(*jt <= 32 && jt != fileEnd && jt.filePos.y == currentY){ //is whitespace
    ++jt; ++substringSize;
  }
	return it.data[it.filePos.y].substr(it.filePos.x, substringSize);
}

ConstWordIterator ConstWordIterator::operator++(){
  bool currentWord = true;
  size_t currentY = it.filePos.y;
  while((*it <= 32 || currentWord == true) && it != fileEnd){
    if(*it <= 32 || it.filePos.y != currentY) currentWord = false;
  }
	return *this;
}

}
