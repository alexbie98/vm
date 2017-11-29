#include "curses/CursesWindow.h"
#include <iostream>

namespace curses {

CursesWindow::CursesWindow(WINDOW* rawWin): rawWin{rawWin} {}

CursesWindow::~CursesWindow(){
	delwin(rawWin);
}

size_t CursesWindow::getHeight()const{
	size_t height, width;
	getmaxyx(rawWin, height, width);
	return height;
}

size_t CursesWindow::getWidth()const{
	size_t height, width;
	getmaxyx(rawWin, height, width);
	return width;
}

// Pos CursesWindow::getRelativePos(){
// 	Pos pos;
// 	getparyx(rawWin, pos.y, pos.x);
// 	return pos;
// }

Pos CursesWindow::getAbsolutePos(){
	Pos pos;
	getparyx(rawWin, pos.y, pos.x);
	return pos;
}

bool CursesWindow::setPos(Pos p){//return bool or int?
	return mvwin(rawWin, p.y, p.x) == OK;
}

bool CursesWindow::setPos(size_t x, size_t y){
	return mvwin(rawWin, y, x) == OK;
}

bool CursesWindow::refresh(){
	return wrefresh(rawWin) == OK;
}

bool CursesWindow::setDrawColor(int color_number){
	return wattron(rawWin, COLOR_PAIR(1)) == OK;
}

int CursesWindow::getDrawColor(){
	int color_number;
	wattr_get(rawWin, (int*)(0), &color_number, (int*)(0));
	return color_number;
}

bool CursesWindow::enableAttribute(int attr){
	return wattron(rawWin, attr) == OK;
}

bool CursesWindow::disableAttribute(int attr){
	return wattroff(rawWin, attr) == OK;
}

bool CursesWindow::drawString(std::string s, int x, int y){
	//return mvwprintw(rawWin, y, x, s.c_str()) == OK;
	return mvwaddstr(rawWin, y, x, s.c_str()) == OK;
}

bool CursesWindow::drawString(std::string s, int x, int y, int color_number){
	bool result;
	wattron(rawWin, COLOR_PAIR(color_number));
	result = mvwaddstr(rawWin, y, x, s.c_str()) == OK;
	wattroff(rawWin, COLOR_PAIR(color_number));
	return result;
}

}
