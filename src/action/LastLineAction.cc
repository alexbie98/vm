#include "action/LastLineAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void LastLineAction::doAction(State& context) {
	File &f = context.getFile();
	size_t last = f.getLines().size()-1;
	f.setCursorPos(Pos{f.getLines()[last].length()-1,last});
}

LastLineAction::LastLineAction( unique_ptr<Action> nextAction):
	Action{1,move(nextAction)} {}

unique_ptr<Action> LastLineAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<LastLineAction>(move(nextClone));
}

LastLineAction::~LastLineAction() {}

}

