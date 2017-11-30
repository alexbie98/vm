#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H
#include <memory>
#include <string>
#include <map>
#include "controller/InputParser.h"

namespace  vm {

class Command;

class CommandModeInputParser {

	private:
		size_t decimal;
		size_t numBuffer;
		size_t multiplier;
		
		std::map<char,std::unique_ptr<Command>> commandMap;
		Command* current;
		
		void addEntries();
		void reset();

	public:
		CommandModeInputParser();

		std::unique_ptr<Action> 
			parseInput(std::unique_ptr<KeyInput> in) override;

		~CommandModeInputParser() override;
};

}

#endif 
