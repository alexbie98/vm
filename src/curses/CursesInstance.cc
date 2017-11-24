#include "CursesInstance.h"

namespace curses {

void CursesInstance::init(){

}

CursesInstance::CursesInstance(){
	init();
}


std::unique_ptr<CursesWindow> CursesInstance::makeCursesWindow(Posn pos, 
		int width, int height) {
	std::unique_ptr<CursesWindow> w = 
		std::make_unique<CursesWindow>(
				create_newwin(height, width, pos.second, pos.first));
	// window init stuff here
	return w;
}

char CursesInstance::getCh(){


}




}
