#include "Editor.h"

using namespace std;
namespace vm {

Editor::Editor(const vector<string>& args): state{new State()},
 controller{new CursesController(cursesInstance)},
 view{new CursesView(cursesInstance)}{
	// add files to the state
	for (const string& s: args){
		state->addFile(s);
	}
	state->addObserver(view.get());
}

int Editor::run(){
	while (state->getRunStatus() == State::RUNNING){
		state->handleInput(controller->getInput());
	}
	return state->getRunStatus();
}

}
