#include "Editor.h"
#include <ncurses.h>
using namespace std;
namespace vm {

Editor::Editor(const vector<string>& args):
  state{new State()},
  controller{new CursesController(cursesInstance)},
  view{new CursesView(cursesInstance)}{
   state->addObserver(view.get());

	// add files to the state
	for (const string& s: args){
		state->addFile(s);
	}
}

int Editor::run(){
	while (state->getRunStatus() == State::RUNNING){
		state->handleInput(controller->getInput());
	}
	return state->getRunStatus();
}

}
