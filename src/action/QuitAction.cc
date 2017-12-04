#include "action/QuitAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void QuitAction::doAction(State& context) {
	context.setRunStatus(State::SAFE_EXIT);
}

QuitAction::QuitAction( unique_ptr<Action> nextAction):
	Action{1,move(nextAction)} {}

unique_ptr<Action> QuitAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<QuitAction>(move(nextClone));
}

QuitAction::~QuitAction() {}

}

