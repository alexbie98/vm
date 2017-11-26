#ifndef CURSES_VIEW_H
#define CURSES_VIEW_H

#include "curses/CursesInstance.h"
#include "curses/CursesWindow.h"
#include "view/View.h"
#include "data/Event.h"

namespace vm {

class CursesView : public View {

	private:
		curses::CursesInstance& cInst;

	public:
		CursesView(curses::CursesInstance& cInst);
		~CursesView() override;
		void beNotified(Event event, State& subject) override;

};

}

#endif
