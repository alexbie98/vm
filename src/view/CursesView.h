#ifndef CURSES_VIEW_H
#define CURSES_VIEW_H

#include "curses/CursesInstance.h"
#include "curses/CursesWindow.h"
#include "view/View.h"
#include "data/Event.h"

namespace vm {

class CursesView : public View {

public:
	void beNotified(Event event, State& subject){};

};

}

#endif
