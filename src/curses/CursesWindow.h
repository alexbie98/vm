#ifndef CURSES_WINDOW_H
#define CURSES_WINDOW_H

#include "ncurses.h"
#include <memory>
#include <utility>
#include "data/Posn.h"

namespace curses {

class CursesWindow {

	private:
		std::unique_ptr<WINDOW> rawWin;
		CursesWindow(WINDOW* rawWin): rawWin{rawWin} {}
	public:
		~CursesWindow();

		int getHeight();
		int getWidth();
		Posn getPos();
		void setPos(Posn p);
		void setPos(size_t x, size_t y);
		void refresh();
		std::pair<size_t, size_t> getDrawColor();
		void setDrawColor(std::pair<size_t, size_t>);
		void setDrawColor(size_t bg, size_t fg);

	friend class CursesInstance;
};


}


#endif

