#include "action/InsertionAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;

namespace vm {

void InsertionAction::doAction(State& context) {
	Pos current = context.getFile().getCursorPos();
	context.getFile().addString(toInsert, current);
}

InsertionAction::InsertionAction(const string& toInsert, size_t multi, 
		std::unique_ptr<Action> nextAction):
	TextChangeAction{multi, move(nextAction)},toInsert{toInsert} {}

unique_ptr<Action> InsertionAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<InsertionAction>(toInsert, multi, move(nextClone));
	
}

InsertionAction::~InsertionAction() {}

}

