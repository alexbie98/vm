#ifndef MODE_H
#define MODE_H

#include <memory>
#include "action/Action.h"

namespace vm {

class Input;
class InputParser;
class Action;

class Mode {

	private:
		std::unique_ptr<InputParser> parser;
	protected:
		Mode(InputParser* parser);
	public:
		virtual ~Mode() = 0;

		std::unique_ptr<Action> parseInput(std::unique_ptr<Input> input);
		virtual void onEnter() = 0;
		virtual void onExit() = 0;


};

}

#endif
