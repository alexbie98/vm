#ifndef REGEX_ATTRIBUTE
#define REGEX_ATTRIBUTE

#include "state/File.h"
#include "state/WordAttribute.h"

namespace vm{

class RegexAttribute: public WordAttribute{
  bool matches(ConstWordIterator it);
};

}

#endif
