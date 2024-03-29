#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H
#include <vector>
#include <memory>

namespace  vm {

// forward declare
class Action;
class KeyInput;
class Input;

class InputParser {

	public:
		virtual std::unique_ptr<Action> 
			parseInput(KeyInput* in) = 0;

		virtual ~InputParser() {}
};

}

#endif 
