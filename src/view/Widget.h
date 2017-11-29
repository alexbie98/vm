#ifndef WIDGET_H
#define WIDGET_H

#include "curses/CursesWindow.h"

namespace vm {

  class State;

class Widget{
protected:
  curses::CursesWindow &win;
public:
  Widget(curses::CursesWindow &win):win{win}{}
	virtual ~Widget(){}

  //return reference? refresh const?
  curses::CursesWindow &getCursesWindow(){return win;}
  virtual void draw(const State &state) = 0;
};

}

#endif
