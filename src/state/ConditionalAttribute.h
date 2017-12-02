#ifndef CONDITIONAL_ATTRIBUTE
#define CONDITIONAL_ATTRIBUTE

#include "state/File.h"
#include "state/WordAttribute.h"

namespace vm{

class ConditonalAttribute: public WordAttribute{

  bool matches(ConstWordIterator it);
};

}

#endif
