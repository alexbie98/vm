#include "action/ChangeModeAction.h"
#include "state/State.h"
#include "state/File.h"
#include "state/mode/TerminalMode.h"
#include "state/mode/TerminalModeInputParser.h"

using namespace std;
namespace vm {

void ChangeModeAction::doAction(State& context) {
	context.setActiveMode(nextMode);
	if (nextMode == typeid(TerminalMode)){
		dynamic_cast<TerminalModeInputParser*>(
				context.getMode().getParser())->setCommandBuffer(string(1,in));
	}
}

ChangeModeAction::ChangeModeAction(const type_info& nextMode, char in,
		unique_ptr<Action> nextAction):
	Action{1,move(nextAction)}, nextMode{nextMode}, in{in} {}

unique_ptr<Action> ChangeModeAction::clone(){
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<ChangeModeAction>(nextMode, in, move(nextClone));
}

ChangeModeAction::~ChangeModeAction() {}

}

