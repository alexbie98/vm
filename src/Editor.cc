#include "Editor.h"

using namespace std;
namespace vm {

	Editor::Editor(const std::vector<string>& args): state{make_unique<State>()},
	 controller{make_unique<CursesController>(cursesInstance)}, view{make_unique<CursesView>()}{
		// add files to the state
		for (const string& s: args){
			state->addFile(s);
		}
		state->addObserver(view.get());
	}

	int Editor::run(){
		while (state->isValid()){
			state->handleInput(controller->getInput());
		}
	}

}
