#ifndef TERMINAL_MODE_INPUT_PARSER_H
#define TERMINAL_MODE_INPUT_PARSER_H

#include "controller/InputParser.h"

namespace  vm {

class TerminalModeInputParser : public InputParser{

	public:

		TerminalModeInputParser();

		std::unique_ptr<Action> 
			parseInput(std::unique_ptr<KeyInput> in) override;

		~TerminalModeInputParser() override;
};

}

#endif 
