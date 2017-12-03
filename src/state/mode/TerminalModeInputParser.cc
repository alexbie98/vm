#include "state/mode/TerminalModeInputParser.h"
#include "controller/KeyInput.h"
#include "action/Action.h"
#include "action/ChangeModeAction.h"
#include <ncurses.h>

using namespace std;

namespace vm {

TerminalModeInputParser::TerminalModeInputParser() {}

unique_ptr<Action> TerminalModeInputParser::parseInput(unique_ptr<KeyInput> in){
	int key = in->getKey();
	return unique_ptr<Action>{};
}

TerminalModeInputParser::~TerminalModeInputParser(){}

}

