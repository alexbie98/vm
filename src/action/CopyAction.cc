#include "action/CopyAction.h"
#include "action/MovementAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {
	
void CopyAction::performOp(State& context, Pos start, Pos end){
	string copyStr = context.getFile().getString(start, end);
	context.getRegister().paste = move(copyStr);
}

CopyAction::CopyAction(unique_ptr<MovementAction> movement, size_t multi, 
		unique_ptr<Action> nextAction): 
	MovementModifiableAction{move(movement), multi, move(nextAction)} {}

CopyAction::~CopyAction() {}

}

