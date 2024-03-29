#ifndef MODE_H
#define MODE_H

#include <memory>
#include "action/Action.h"
#include <string>

namespace vm {

class Input;
class InputParser;
class Action;

class Mode {

	private:
		std::unique_ptr<InputParser> parser;
		std::string name;
	protected:
		Mode(std::unique_ptr<InputParser> parser, const std::string& name);
	public:
		InputParser* getParser();
		const InputParser* getParser()const;
		virtual ~Mode();

		std::string getName();
		std::unique_ptr<Action> parseInput(Input* input);
		virtual void onEnter() = 0;
		virtual void onExit() = 0;
		virtual void reset() = 0;


};

}

#endif
