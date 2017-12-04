#include "state/mode/InsertModeInputParser.h"
#include "controller/KeyInput.h"
#include "action/Action.h"
#include "action/InsertionAction.h"
#include "action/DeleteAction.h"
#include "action/DirectionalMovementAction.h"
#include "action/ChangeModeAction.h"
#include "state/mode/CommandMode.h"
#include <ncurses.h>
#include <iostream>

using namespace std;

namespace vm {

InsertModeInputParser::InsertModeInputParser() {}

unique_ptr<Action> InsertModeInputParser::parseInput(KeyInput* in){
	int key = in->getKey();

	switch (key){
		// ASCII 27 = esc key
		case 27: return make_unique<ChangeModeAction>(typeid(CommandMode));

		case KEY_UP: return make_unique<DirectionalMovementAction>(UP);
		case KEY_DOWN: return make_unique<DirectionalMovementAction>(DOWN);
		case KEY_LEFT: return make_unique<DirectionalMovementAction>(LEFT);
		case KEY_RIGHT: return make_unique<DirectionalMovementAction>(RIGHT);
		case KEY_BACKSPACE: return make_unique<DeleteAction>();
		default: {
			if (key>=32 && key<=126){ //needs to go in helper
				return make_unique<InsertionAction>(
						string(1,(static_cast<char>(key))));
			}
			else return unique_ptr<Action>{};
		}
	}
}

InsertModeInputParser::~InsertModeInputParser(){}

}
