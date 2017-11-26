#include "curses/CursesWindow.h"

namespace curses {

CursesWindow::CursesWindow(WINDOW* rawWin): rawWin{rawWin} {}

CursesWindow::~CursesWindow(){
	delwin(rawWin);
}

size_t CursesWindow::getHeight(){
	size_t height, width;
	getmaxyx(rawWin, height, width);
	return height;
}

size_t CursesWindow::getWidth(){
	size_t height, width;
	getmaxyx(rawWin, height, width);
	return width;
}

// Posn CursesWindow::getRelativePos(){
// 	Posn pos;
// 	getparyx(rawWin, pos.second, pos.first);
// 	return pos;
// }

Posn CursesWindow::getAbsolutePos(){
	Posn pos;
	getparyx(rawWin, pos.second, pos.first);
	return pos;
}

bool CursesWindow::setPos(Posn p){//return bool or int?
	return mvwin(rawWin, p.second, p.first) == OK;
}

bool CursesWindow::setPos(size_t x, size_t y){
	return mvwin(rawWin, y, x) == OK;
}

bool CursesWindow::refresh(){
	return wrefresh(rawWin) == OK;
}

bool setDrawColor(std::pair<size_t, size_t>){
	return attron(COLOR_PAIR(1)) == OK;
}

void setDrawColor(size_t bg, size_t fg){

}

}
