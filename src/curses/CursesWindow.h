#ifndef CURSES_WINDOW_H
#define CURSES_WINDOW_H

#include <ncurses.h>
#include <memory>
#include <utility>
#include "data/Posn.h"

namespace curses {

class CursesWindow {

	private:
		WINDOW* rawWin;
		CursesWindow(WINDOW* rawWin);
	public:
		~CursesWindow();

		size_t getHeight();
		size_t getWidth();
		// //If window is a subwindow, returns windows origin relative to parent window
		// Posn getRelativePos();
		//Absolute screen coords of windows origin
		Posn getAbsolutePos();
		//Do not use to move subwindow
		bool setPos(Posn p);
		bool setPos(size_t x, size_t y);
		bool refresh();
		bool setDrawColor(int color_number);
		//void setDrawColor(size_t bg, size_t fg);

	friend class CursesInstance;
};


}


#endif
