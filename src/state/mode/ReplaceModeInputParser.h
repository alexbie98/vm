#ifndef REPLACE_MODE_INPUT_PARSER_H
#define REPLACE_MODE_INPUT_PARSER_H

#include "controller/InputParser.h"

namespace  vm {

class TextChangeAction;

class ReplaceModeInputParser : public InputParser{

	public:

		ReplaceModeInputParser();

		std::unique_ptr<Action> parseInput(KeyInput* in) override;

		~ReplaceModeInputParser() override;
};

}

#endif 
