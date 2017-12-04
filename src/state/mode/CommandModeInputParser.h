#ifndef COMMAND_MODE_INPUT_PARSER_H
#define COMMAND_MODE_INPUT_PARSER_H

#include <memory>
#include <string>
#include <map>
#include "controller/InputParser.h"

namespace  vm {


class CommandModeInputParser : public InputParser{

	private:
		size_t numBuffer;
		size_t multiplier;
		std::unique_ptr<Action> current;
		void addEntries();

	public:
		void reset();

		CommandModeInputParser();

		std::unique_ptr<Action> parseInput(KeyInput* in) override;

		~CommandModeInputParser() override;
};

}

#endif 
