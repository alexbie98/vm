#include "state/command/AtCommand.h"
#include "action/RunMacroAction.h"

using namespace std;
namespace vm {

AtCommand::AtCommand(): Command{'@'} {}

std::unique_ptr<Action> AtCommand::getAction(int key, 
		unordered_map<int, unique_ptr<Command>>* const map) {
	return make_unique<RunMacroAction>(key);
}

AtCommand::~AtCommand() {}

}
