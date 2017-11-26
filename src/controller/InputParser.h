#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H
#include <vector>
#include <memory>

namespace  vm {

// forward declare
class Action;
class CursesInput;
class Input;

class InputParser {

	private:
		std::vector<std::unique_ptr<Input>> inputBuffer;
	public:
		virtual std::unique_ptr<Action> 
			parseInput(std::unique_ptr<CursesInput> in) = 0;

		virtual ~InputParser() = 0;
};

}

#endif 
