#ifndef DICTIONARY_ATTRIBUTE
#define DICTIONARY_ATTRIBUTE

#include "state/File.h"
#include "state/WordAttribute.h"
#include <unordered_map>
#include <string>

namespace vm{

class DictionaryAttribute: public WordAttribute{
  std::unordered_map<std::string, int> dict;
public:
  DictionaryAttribute(int precedence, int syntax):WordAttribute(precedence, syntax){}
  void addKey(const std::string &k){dict[k] = 1;}
  bool matches(ConstWordIterator it){return !(dict.find(*it) == dict.end());}
};

}

#endif
