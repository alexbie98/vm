#ifndef WINDOW_H
#define WINDOW_H

#include "view/Widget.h"
#include "curses/CursesInstance.h"
#include "data/Pos.h"
#include <utility>

class State;

namespace vm{

class Window: public Widget{ //rename widgets?  WindowWidget?
  std::unique_ptr<curses::CursesWindow> cursesWindow; // unique_ptr?
public: // cwindow cpy ctor
  Window(std::unique_ptr<curses::CursesWindow> cursesWindow):
    Widget{*cursesWindow}, cursesWindow{std::move(cursesWindow)}{}

  void draw(const State& state){};
};

}

#endif
