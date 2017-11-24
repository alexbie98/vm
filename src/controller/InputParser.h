#ifndef INPUT_H
#define INPUT_H
#include <vector>

namespace  vm {

// forward declare
class Action;
class Input;

class InputParser {

	private:
		std::vector<Input> inputBuffer;	
	public:
		Action parseInput();
};

}

#endif 
