#include "view/CursesView.h"

namespace vm {

	CursesView::CursesView(curses::CursesInstance& cInst): cInst{cInst}{
	
	}	

	void CursesView::beNotified(Event event, State& subject){

	}

	CursesView::~CursesView(){}

}
