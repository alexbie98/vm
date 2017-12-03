#include "action/ChangeModeAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void ChangeModeAction::doAction(State& context) {
	context.setActiveMode(nextMode);
}

ChangeModeAction::ChangeModeAction(const type_info& nextMode,
		unique_ptr<Action> nextAction):
	Action{1,move(nextAction)}, nextMode{nextMode} {}

unique_ptr<Action> ChangeModeAction::clone(){
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<ChangeModeAction>(nextMode, move(nextClone));
}

ChangeModeAction::~ChangeModeAction() {}

}

