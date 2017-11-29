#ifndef CURSES_VIEW_H
#define CURSES_VIEW_H

#include "curses/CursesInstance.h"
#include "curses/CursesWindow.h"
#include "view/View.h"
#include "data/Event.h"
#include "view/Widget.h"
#include <utility>

class State;

namespace vm {

class CursesView : public View {
		curses::CursesInstance& cInst;
		std::unique_ptr<Widget> widget;

		void draw(const State &state);

	public:
		CursesView(curses::CursesInstance& cInst);
		~CursesView() override;

		void beNotified(Event event, State& subject) override;
};

}

#endif
