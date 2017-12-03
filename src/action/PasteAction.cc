#include "action/PasteAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;

namespace vm {

void PasteAction::doAction(State& context) {
	File& f = context.getFile();
	f.addString(context.getRegister().paste, f.getCursorPos());
}

PasteAction::PasteAction(size_t multi, std::unique_ptr<Action> nextAction):
	Action{multi,move(nextAction)} {}

PasteAction::~PasteAction() {}

}

