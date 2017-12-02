#ifndef DICTIONARY_ATTRIBUTE
#define DICTIONARY_ATTRIBUTE

#include "state/File.h"
#include "state/WordAttribute.h"
#include <unordered_map>
#include <string>

namespace vm{

class DictionaryAttribute: public WordAttribute{
  std::unordered_map<std::string> dict;
public:
  bool matches(ConstWordIterator it){return dict.find(*it) != unordered_map::end;}
};

}

#endif
