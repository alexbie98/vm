#ifndef CURSES_H
#define CURSES_H
#include <ncurses.h>
#include "curses/CursesWindow.h"
#include "data/Posn.h"
#include <vector>

namespace curses {

class CursesInstance {
	private:
		void init();
	public:
		CursesInstance();
		char getCh();
		std::unique_ptr<CursesWindow> makeCursesWindow(Posn pos,
				int width, int height);

};

}

#endif
