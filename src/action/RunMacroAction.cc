#include "action/RunMacroAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void RunMacroAction::doAction(State& context) {
	context.getRegister().macroMap.at(key)->execute(context);
}

RunMacroAction::RunMacroAction(int key,
		size_t multi, unique_ptr<Action> nextAction):
	Action{multi,move(nextAction)}, key{key} {}

std::unique_ptr<Action> RunMacroAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<RunMacroAction>(key, multi, move(nextClone));
}


RunMacroAction::~RunMacroAction() {}

}

