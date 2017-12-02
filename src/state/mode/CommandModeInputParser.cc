#include "state/mode/CommandModeInputParser.h"
#include "state/command/Command.h"
#include "state/command/SimpleCommand.h"
#include "controller/KeyInput.h"
#include "action/Action.h"

using namespace std;
namespace vm {

void CommandModeInputParser::reset(){
	decimal = 1;
	numBuffer = 0;
	multiplier = 1;
	current  = nullptr;
}		

void CommandModeInputParser::addEntries(){
	
	// ADD ENTRIES FOR ALL COMMMANDS

}

CommandModeInputParser::CommandModeInputParser(): decimal{1}, numBuffer{0},
	multiplier{1}, current{nullptr} {
	addEntries();
}


unique_ptr<Action> CommandModeInputParser::parseInput(unique_ptr<KeyInput> in){
	char key = in->getKey();

	return unique_ptr<Action>{};
}

CommandModeInputParser::~CommandModeInputParser(){}

}

