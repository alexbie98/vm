#include "action/SaveFileAction.h"
#include "state/State.h"
#include "state/File.h"
#include "util/FileWriter.h"

using namespace std;
namespace vm {

void SaveFileAction::doAction(State& context) {
	util::FileWriter fw;
	fw.writeLines(context.getFile().getName(), context.getFile().getLines());
}

SaveFileAction::SaveFileAction(unique_ptr<Action> nextAction):
	Action{1,move(nextAction)} {}

unique_ptr<Action> SaveFileAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<SaveFileAction>(move(nextClone));
}

SaveFileAction::~SaveFileAction() {}

}

