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
  virtual bool matches(ConstWordIterator it) = 0;
};

}

#endif
