#ifndef COMMAND_MODE_INPUT_PARSER_H
#define COMMAND_MODE_INPUT_PARSER_H

#include <memory>
#include <string>
#include <unordered_map>
#include "controller/InputParser.h"

namespace  vm {

class Command;

class CommandModeInputParser : public InputParser{

	private:
		size_t decimal;
		size_t numBuffer;
		size_t multiplier;
		
		std::unordered_map<int,std::unique_ptr<Command>> commandMap;
		std::unique_ptr<Command> current;
		
		void addEntries();

	public:
		void reset();

		CommandModeInputParser();

		std::unique_ptr<Action> parseInput(KeyInput* in) override;

		~CommandModeInputParser() override;
};

}

#endif 
