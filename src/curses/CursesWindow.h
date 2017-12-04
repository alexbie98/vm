#ifndef CURSES_WINDOW_H
#define CURSES_WINDOW_H

#include <ncurses.h>
#include <memory>
#include <utility>
#include <string>
#include "data/Pos.h"

namespace curses {

class CursesWindow {

	private:
		WINDOW* rawWin;
		CursesWindow(WINDOW* rawWin);
	public:
		//add move ctor/assignment
		//add const qualifiers
		~CursesWindow();

		size_t getHeight()const;
		size_t getWidth()const;
		// //If window is a subwindow, returns windows origin relative to parent window
		// Pos getRelativePos();
		//Absolute screen coords of windows origin
		Pos getAbsolutePos();
		//Do not use to move subwindow
		bool setPos(Pos p);
		bool setPos(size_t x, size_t y);
		bool refresh();
		bool setDrawColor(int color_number);
		int getDrawColor();
		bool enableAttribute(int attr);
		bool disableAttribute(int attr);
		// Draw string current color and attributes set
		bool drawString(std::string s, size_t x, size_t y);
		// Draw string specified color and current attributes set
		bool drawString(std::string s, size_t x, size_t y, int color_number);


	friend class CursesInstance;
};


}


#endif
