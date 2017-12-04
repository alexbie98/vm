#include "state/command/CCommand.h"
#include "state/mode/InsertMode.h"
#include "action/ChangeModeAction.h"
#include "action/DeleteAction.h"
#include "action/ClearInputBufferAction.h"

using namespace std;
namespace vm {

CCommand::CCommand(): Command{'c'} {}

unique_ptr<Action> CCommand::getAction(int key, 
		map<int, Command*>* const map) {
	if (key == 'c'){
	}
	else if (map->at(key)->isMovement()){
		return make_unique<DeleteAction>(map->at(key)->getAction(),
				1, make_unique<ChangeModeAction>(typeid(InsertMode)));
	}
	else return make_unique<ClearInputBufferAction>();

}		
CCommand::~CCommand() {}

}

