#ifndef FILETEXT_H
#define FILETEXT_H

#include "view/WidgetDecorator.h"
#include <unordered_map>
#include <vector>

namespace vm{

  struct WordIndicator;

class FileText: public WidgetDecorator{
  size_t currentLine;
  //syntax, color
  const std::unordered_map<int, int> &syntaxColorMap;

  // Takes y coordinate to print string, returns next line after
  // lines printed and wrapped.
  size_t drawLineWithWrap(const std::string &s, size_t y);
  size_t drawLineWithWrap(const std::string &s, size_t y, std::vector<std::pair<Pos, size_t> >::const_iterator &it);
  size_t drawLineWithWrap(const std::string &s, size_t y, std::vector<std::pair<Pos, int> >::const_iterator &it, int &insideRange);

public:
  // add override keywords
  FileText(const std::unordered_map<int, int> &syntaxColorMap, std::unique_ptr<Widget> widget):
    WidgetDecorator(std::move(widget)), currentLine{0}, syntaxColorMap(syntaxColorMap){}
  void draw(const State& state);
};

}

#endif
