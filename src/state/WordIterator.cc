#include "state/WordIterator.h"
#include "util/Word.h"
#include <iostream>

using namespace std;
namespace vm {

// ConstWordIterator implementations ----------------------------------------

ConstWordIterator::ConstWordIterator(const vector<string>& data,
	Pos filePos): it{data, filePos},
                fileEnd{ConstCharIterator(data, Pos(data[data.size() - 1].size(),data.size() - 1))}{

      if(it.filePos.x == 0){
        while(!utils::isValidWordChar(*it) && it != fileEnd) ++it; //is whitespace
      }
      else if(!utils::isValidWordChar(*(it.minusOne()))){
        while(!utils::isValidWordChar(*it) && it != fileEnd) ++it;
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
  while(!utils::isValidWordChar(*jt) && jt != fileEnd && jt.filePos.y == currentY){ //is whitespace
    ++jt; ++substringSize;
  }
	return it.data[it.filePos.y].substr(it.filePos.x, substringSize);
}

ConstWordIterator ConstWordIterator::operator++(){
  bool currentWord = true;
  size_t currentY = it.filePos.y;
  while((!utils::isValidWordChar(*it) || currentWord == true) && it != fileEnd){
    if(!utils::isValidWordChar(*it) || it.filePos.y != currentY) currentWord = false;
  }
	return *this;
}

Pos ConstWordIterator::getPos(){
	return it.getPos();
}

}
