#include "action/DeleteAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {
	
void DeleteAction::performOp(State& context, Pos start, Pos end){
	context.getFile().removeString(start, end);
}

DeleteAction::DeleteAction(unique_ptr<MovementAction> movement, size_t multi,
		unique_ptr<Action> nextAction): 
	MovementModifiableAction{move(movement), multi, move(nextAction)} {}


unique_ptr<Action> DeleteAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextAction) nextClone = nextAction->clone();
	unique_ptr<MovementAction> movementClone{
		dynamic_cast<MovementAction*>(getMovement()->clone().release())};

	return make_unique<DeleteAction>(move(movementClone), multi, 
			move(nextClone));
}

DeleteAction::~DeleteAction() {}

}



