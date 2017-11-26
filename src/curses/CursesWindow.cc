#include "curses/CursesWindow.h"

namespace curses {

CursesWindow::CursesWindow(WINDOW* rawWin): rawWin{rawWin} {}

int CursesWindow::getHeight(){
	return 0;
}

int CursesWindow::getWidth(){
	return 0;
}

}
