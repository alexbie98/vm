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

	File& f = context.getFile();

	Pos start = f.toLineCoords(f.getCursorPos());
	if (movement) movement->execute(context);
	Pos end = f.toLineCoords(f.getCursorPos());

	if (end.y < start.y || (end.y == start.y && end.x < start.x)){
		swap(start,end);
  }

	performOp(context, start, end);
}

MovementModifiableAction::~MovementModifiableAction(){}
				
}




