#include "view/CursesView.h"
#include "view/FileText.h"
#include "view/Window.h"
#include "curses/CursesConstants.h"

#include <iostream>

namespace vm {

	CursesView::CursesView(curses::CursesInstance& cInst): cInst{cInst}{
		//make default mode

		//Make window same size as the screen
		std::unique_ptr<curses::CursesWindow> cursesWindow =
			cInst.makeCursesWindow(Pos{0,0},
														 cInst.getScreenWidth(),
														 cInst.getScreenHeight());
		widget = std::make_unique<FileText>(std::make_unique<Window>(std::move(cursesWindow)));

		// Initialize color pallet
		//cInst.initColorPair(1, curses::color:White, curses::color::Black);
	}

	void CursesView::draw(const State& state){
		//add different mode display
		widget->draw(state);
		widget->getCursesWindow().refresh();
	}

	void CursesView::beNotified(Event event, State& subject){
		switch(event){
			case FILE_ADDED:
				draw(subject);
				break;
			case ACTION_EXECUTED:
				draw(subject);
			default:
				break;
		}

	}

	CursesView::~CursesView(){}

}
