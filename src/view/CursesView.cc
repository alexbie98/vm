#include "view/CursesView.h"
#include "view/FileText.h"
#include "view/Window.h"
#include "curses/CursesConstants.h"
#include "state/SyntaxConstants.h"

#include <iostream>
#include <unordered_map>

namespace vm {

	CursesView::CursesView(curses::CursesInstance& cInst): cInst{cInst}{
		//make default mode

		// Initialize color pallet
		cInst.initColorPair(2, curses::color::Yellow, curses::color::Default);
		cInst.initColorPair(3, curses::color::Green, curses::color::Default);
		cInst.initColorPair(4, curses::color::Blue, curses::color::Default);

		// Create map of syntax identifiers to colors
		std::unordered_map<int, int> syntaxColorMap ({{syntax::DoubleQuote,2},
																								 {syntax::Keyword, 4},
																								 {syntax::MultiLineComment, 3}});

		//Make window same size as the screen
		std::unique_ptr<curses::CursesWindow> cursesWindow =
			cInst.makeCursesWindow(Pos{0,0},
														 cInst.getScreenWidth(),
														 cInst.getScreenHeight());
		widget = std::make_unique<FileText>(syntaxColorMap, std::make_unique<Window>(std::move(cursesWindow)));

		//TODO Make constants
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
			default:
				break;
		}

	}

	CursesView::~CursesView(){}

}
