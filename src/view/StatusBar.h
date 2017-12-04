#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "view/WidgetDecorator.h"

namespace vm{

class StatusBar: public WidgetDecorator{
  void drawLineNumber(const State &state, size_t windowWidth, size_t windowHeight);

public:

  StatusBar(std::unique_ptr<Widget> widget): WidgetDecorator(std::move(widget)){}

  void draw(const State& state) override;
};

}

#endif
