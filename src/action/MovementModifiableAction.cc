#include "action/MovementModifiableAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;

namespace vm {

MovementModifiableAction::MovementModifiableAction(
		unique_ptr<Action> movement, size_t multi, 
		unique_ptr<Action> nextAction):
	Action{multi, move(nextAction)}, movement{move(movement)} {}

void MovementModifiableAction::doAction(State& context){
	Pos start = context.getFile().getCursorPos();
	if (movement) movement->execute(context);
	Pos end = context.getFile().getCursorPos();
	performOp(context, start, end);
}

MovementModifiableAction::~MovementModifiableAction(){}
				
}




