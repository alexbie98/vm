#include "action/ClearInputBufferAction.h"
#include "state/State.h"
#include "state/File.h"
#include "state/mode/Mode.h"

using namespace std;
namespace vm {

void ClearInputBufferAction::doAction(State& context) {
	context.getMode().reset();

}

ClearInputBufferAction::ClearInputBufferAction(unique_ptr<Action> nextAction):
	Action{1,move(nextAction)} {}

unique_ptr<Action> ClearInputBufferAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<ClearInputBufferAction>(move(nextClone));
}

ClearInputBufferAction::~ClearInputBufferAction() {}

}

