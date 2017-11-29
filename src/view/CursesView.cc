#include "view/CursesView.h"
#include "view/FileText.h"
#include "view/Window.h"

#include <iostream>

namespace vm {

	CursesView::CursesView(curses::CursesInstance& cInst): cInst{cInst}{
		//make default mode

		//Make window same size as the screen
		std::unique_ptr<curses::CursesWindow> cursesWindow =
			cInst.makeCursesWindow(Pos{0,0},
														 cInst.getScreenWindow().getWidth(),
														 cInst.getScreenWindow().getHeight());
		widget = std::make_unique<FileText>(std::make_unique<Window>(std::move(cursesWindow)));
	}

	void CursesView::draw(const State& state){
		//add different mode display
		widget->draw(state);
		widget->getCursesWindow().refresh();
	}

	void CursesView::beNotified(Event event, State& subject){
		//std::cout<< "test" <<std::endl;
		switch(event){
			case FILE_ADDED:
				draw(subject);
				break;
			default:
				break;
		}

	}

	CursesView::~CursesView(){}

}
