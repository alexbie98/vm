#ifndef INDICATOR_PACK_H
#define INDICATOR_PACK_H

#include "state/WordAttribute.h"
#include "state/RangeAttribute.h"
#include <map>
#include <utility>
#include "data/Pos.h"

namespace vm{

struct WordIndicator{
  int precendence;
  int syntax;
  std::vector<std::pair<Pos, size_t> > words;
};

struct IndicatorPack{ //make class
  std::vector<WordIndicator> wordIndicators;
  //Position and syntax number
  std::vector<std::pair<Pos, int> > rangeIndicators;
};

}

#endif
