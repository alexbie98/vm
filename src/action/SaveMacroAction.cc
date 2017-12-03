#include "action/SaveMacroAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void SaveMacroAction::doAction(State& context) {
	unique_ptr<Action> completeMacro = context.saveCurrentMacro();
	context.getRegister().macroMap[key] = (move(completeMacro));
}

SaveMacroAction::SaveMacroAction(int key,
		unique_ptr<Action> nextAction):
	Action{1,move(nextAction)}, key{key} {}

std::unique_ptr<Action> SaveMacroAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<SaveMacroAction>(key, move(nextClone));

}

SaveMacroAction::~SaveMacroAction() {}

}

