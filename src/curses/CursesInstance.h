#ifndef CURSES_INSTANCE_H
#define CURSES_INSTANCE_H
#include <ncurses.h>
#include "curses/CursesWindow.h"
#include "data/Pos.h"
#include <vector>

namespace curses {

class CursesInstance {
public:
	CursesInstance();
	~CursesInstance();
	char getCh();

	size_t getScreenHeight()const;
	size_t getScreenWidth()const;
	const CursesWindow &getScreenWindow();
	std::unique_ptr<CursesWindow> makeCursesWindow(Pos pos, int width, int height);
	void initColorPair(int color_number, int fg_color, int bg_color);
};

}

#endif
