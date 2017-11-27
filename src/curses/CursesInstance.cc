#include "CursesInstance.h"

using namespace std;

namespace curses {

CursesInstance::CursesInstance(){
	initscr();
	start_color();
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

char CursesInstance::getCh(){

}

void initColorPair(int color_number, int fg_color, int bg_color){
	init_pair(color_number, fg_color, bg_color);
}

}
