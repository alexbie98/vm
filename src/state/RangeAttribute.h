#ifndef RANGE_ATTRIBUTE
#define RANGE_ATTRIBUTE

#include <string>

namespace vm{
class RangeAttribute{
  const int syntax;
  const std::string startIndicator;
  const std::string endIndicator;
public:
  RangeAttribute(int syntax,
                 const std::string &startIndicator,
                 const std::string &endIndicator):
  syntax{syntax}, startIndicator{startIndicator}, endIndicator{endIndicator}{}
  const std::string &getStartIndicator()const{return startIndicator;}
  const std::string &getEndIndicator()const{return endIndicator;}
  int getSyntax() const {return syntax;}
};
}

#endif
