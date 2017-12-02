#ifndef INDICATOR_PACK_H
#define INDICATOR_PACK_H

#include "state/WordAttribute.h"
#include "state/RangeAttribute.h"
#include <map>
#include "data/Pos.h"

namespace vm{

struct RangeIndicator{
  int syntax;
  std::vector<Pos> ranges;
};

struct WordIndicator{
  int precendence;
  int syntax;
  std::vector<Pos> words;
};

struct IndicatorPack{ //make class
  std::vector<WordIndicator> wordIndicators;
  std::vector<RangeIndicator> rangeIndicators;
};

}

#endif
