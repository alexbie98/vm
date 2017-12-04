#include "action/DeleteAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {
	
void DeleteAction::performOp(State& context, Pos start, Pos end){
	File& f = context.getFile();
	f.removeString(start, end);
	f.setCursorPos(f.toScreenCoords(start));
}

DeleteAction::DeleteAction(unique_ptr<Action> movement, size_t multi,
		unique_ptr<Action> nextAction): 
	MovementModifiableAction{move(movement), multi, move(nextAction)} {}


unique_ptr<Action> DeleteAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextAction) nextClone = nextAction->clone();
	return make_unique<DeleteAction>(movement->clone(), multi, 
			move(nextClone));
}

DeleteAction::~DeleteAction() {}

}



