#include "state/mode/CommandModeInputParser.h"
#include "state/mode/Command.h"

namespace vm {

void CommandModeInputParser::reset(){
	decimal = 1;
	numBuffer = 0;
	multiplier = 1;
	current  = nullptr;
}		

void CommandModeInputParser::addEntries(){
	


}

CommandModeInputParser::CommandModeInputParser(): decimal{1}, numBuffer{0},
	multiplier{1}, current{nullptr} {
	addEntries();
}



std::unique_ptr<Action> 
			parseInput(std::unique_ptr<KeyInput> in) override;

		~CommandModeInputParser() override;







}
