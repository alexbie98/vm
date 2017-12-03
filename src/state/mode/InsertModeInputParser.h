#ifndef INSERT_MODE_INPUT_PARSER_H
#define INSERT_MODE_INPUT_PARSER_H

#include "controller/InputParser.h"

namespace  vm {

class TextChangeAction;

class InsertModeInputParser : public InputParser{

	public:

		InsertModeInputParser();

		std::unique_ptr<Action> parseInput(KeyInput* in) override;

		~InsertModeInputParser() override;
};

}

#endif 
