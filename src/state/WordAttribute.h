#ifndef WORD_ATTRIBUTE
#define WORD_ATTRIBUTE

#include "state/File.h"

namespace vm{

  class WordIterator;

class WordAttribute{
protected:
  const int precedence;
  const int syntax;
public:
  WordAttribute(int precedence, int syntax):precedence{precedence}, syntax{syntax}{}
  virtual bool matches(ConstWordIterator it) = 0;
};

}

#endif
