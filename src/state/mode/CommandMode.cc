#include "state/mode/CommandMode.h"
#include "state/mode/CommandModeInputParser.h"

using namespace std;
namespace vm {

CommandMode::CommandMode(): 
	Mode{make_unique<CommandModeInputParser>(), "COMMAND"} {}

CommandMode::~CommandMode(){}

void CommandMode::onEnter(){}

void CommandMode::onExit(){
	reset();
}

void CommandMode::reset(){
	CommandModeInputParser* parserPtr = 
		dynamic_cast<CommandModeInputParser*>(getParser());
	parserPtr->reset();
}

}
