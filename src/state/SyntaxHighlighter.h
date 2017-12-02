#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include "state/WordAttribute.h"
#include "state/RangeAttribute.h"
#include <vector>
#include <memory>

namespace vm{

struct SyntaxHighlighter{
  std::vector<std::unique_ptr<WordAttribute> > wordAttributes;
  std::vector<RangeAttribute> rangeAttributes;
};
}

#endif
