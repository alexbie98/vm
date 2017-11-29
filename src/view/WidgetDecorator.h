#ifndef WIDGETDECORATOR_H
#define WIDGETDECORATOR_H

#include <utility>
#include "Widget.h"

namespace vm{

class WidgetDecorator: public Widget{
protected:
  std::unique_ptr<Widget> widget;
public:
  WidgetDecorator(std::unique_ptr<Widget> widget):
    Widget{widget->getCursesWindow()}, widget{std::move(widget)}{}
};

}

#endif
