#include "state/command/DCommand.h"
#include "action/DeleteAction.h"
#include "action/ClearInputBufferAction.h"

using namespace std;
namespace vm {

DCommand::DCommand(): Command{'d'} {}

unique_ptr<Action> DCommand::getAction(int key, 
		unordered_map<int, unique_ptr<Command>>* const map) {
	if (key == 'd'){
		//TODO:
	}
	else if (map->at(key)->isMovement()){
		return make_unique<DeleteAction>(map->at(key)->getAction());
	}
	else return make_unique<ClearInputBufferAction>();

	
	
}		
DCommand::~DCommand() {}

}

