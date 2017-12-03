#include "action/DirectionalMovementAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void DirectionalMovementAction::doAction(State& context){
	context.getFile().moveCursor(d);
}

DirectionalMovementAction::DirectionalMovementAction(Direction d,
		size_t multi, unique_ptr<Action> nextAction):
	MovementAction{multi, move(nextAction)}, d{d} {}
		
unique_ptr<Action> DirectionalMovementAction::clone(){
	unique_ptr<Action> nextClone;
	if (nextAction) nextClone = nextAction->clone();
	
	return make_unique<DirectionalMovementAction>(d, multi, 
			move(nextClone));
}

DirectionalMovementAction::~DirectionalMovementAction() {}

}
