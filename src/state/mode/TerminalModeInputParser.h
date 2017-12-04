#ifndef TERMINAL_MODE_INPUT_PARSER_H
#define TERMINAL_MODE_INPUT_PARSER_H

#include <string>
#include "controller/InputParser.h"

namespace  vm {

class TerminalModeInputParser : public InputParser{

	private:
		std::string commandBuffer;
		size_t cursor;
		void addCh(char c);
		void delCh();

	public:
		TerminalModeInputParser();

		std::unique_ptr<Action> parseInput(KeyInput* in) override;
		
		std::string getCommandBuffer() const;
		void setCommandBuffer(std::string s);
		size_t getCursorPos() const;
		void reset();

		~TerminalModeInputParser() override;
};

}

#endif 
