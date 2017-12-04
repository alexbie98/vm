#include "CursesInstance.h"
#include <iostream>
#include "util/Word.h"

using namespace std;

namespace curses {

CursesInstance::CursesInstance(){
	initscr();
	start_color();
	use_default_colors();
	size_t height, width;
	getmaxyx(stdscr, height, width);

	//input init
	set_tabsize(utils::TabSize);
	set_escdelay(1);
	keypad(stdscr,TRUE);
	refresh();
	noecho();
	cbreak();
}

CursesInstance::~CursesInstance(){
	endwin();
}


std::unique_ptr<CursesWindow> CursesInstance::makeCursesWindow(Pos pos,
		int width, int height) {
	std::unique_ptr<CursesWindow> w =
		unique_ptr<CursesWindow>(new CursesWindow(newwin(height, width, pos.y, pos.x)));
	//window init stuff here
	return w;
}

size_t CursesInstance::getScreenHeight()const{
	size_t height, width;
	getmaxyx(stdscr, height, width);
	return height;
}

size_t CursesInstance::getScreenWidth()const{
	size_t height, width;
	getmaxyx(stdscr, height, width);
	return width;
}

int CursesInstance::getChar(){
	return getch();
}

void CursesInstance::initColorPair(int color_number, int fg_color, int bg_color){
	init_pair(color_number, fg_color, bg_color);
}

}
