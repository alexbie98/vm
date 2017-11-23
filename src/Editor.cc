#include "Editor.h"

using namespace std;
namespace vm {

	Editor::Editor(const std::vector<string>& args): state{new State()},
	 View{new CursesView()}, Controller{new CursesController()}: {	
		// add files to the state
		for (const string& s: args){
			state->addFile(s);
		}
		state->addObserver(view);
	}

	int Editor::run(){
		while (state->isValid()){
			state->handleInput(controller->getInput());
		}
	}

}
