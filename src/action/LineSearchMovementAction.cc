#include "action/LineSearchMovementAction.h"
#include "state/State.h"
#include "state/File.h"
#include <string>

using namespace std;
namespace vm {

void LineSearchMovementAction::doAction(State& context) {
	
	File& f = context.getFile();
	if (forward){
		size_t found = 
			f.getLines()[f.getCursorPos().y].find(string(1,search),
					f.getCursorPos().x);
		if (found!= string::npos) {
			f.setCursorPos(Pos{found,f.getCursorPos().y});
		}
	}
	else {
		size_t found = 
			f.getLines()[f.getCursorPos().y].rfind(string(1,search),
					f.getCursorPos().x);
		if (found!= string::npos) {
			f.setCursorPos(Pos{found,f.getCursorPos().y});
		}
	}
}

LineSearchMovementAction::LineSearchMovementAction(bool forward, char 
		search, size_t multi, unique_ptr<Action> nextAction):
	Action{multi,move(nextAction)}, forward{forward}, 
	search{search} {}

unique_ptr<Action> LineSearchMovementAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<LineSearchMovementAction>(forward, 
			search, multi, move(nextClone));
}

LineSearchMovementAction::~LineSearchMovementAction() {}

}

