#ifndef CURSES_H
#define CURSES_H
#include <ncurses.h>
#include "curses/CursesWindow.h"
#include "data/Pos.h"
#include <vector>

namespace curses {

class CursesInstance {
	CursesWindow screenWindow;
public:
	CursesInstance();
	~CursesInstance();
	char getCh();
	Pos getScreenSize();

	const CursesWindow &getScreenWindow();
	std::unique_ptr<CursesWindow> makeCursesWindow(Pos pos, int width, int height);
	void initColorPair(int color_number, int fg_color, int bg_color);

};

}

#endif
