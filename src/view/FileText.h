#ifndef FILETEXT_H
#define FILETEXT_H

#include "view/WidgetDecorator.h"

namespace vm{

class FileText: public WidgetDecorator{
  size_t currentLine;
public:
  //add override keywords
  FileText(std::unique_ptr<Widget> widget):
    WidgetDecorator(std::move(widget)), currentLine{0}{}
  void draw(const State& state);
};

}

#endif
