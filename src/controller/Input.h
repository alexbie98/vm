#ifndef INPUT_H
#define INPUT_H
#include <memory>
#include "controller/InputParser.h"

namespace vm {

// forward declare
class Action;
class InputParser;

class Input {
	public:
		virtual std::unique_ptr<Action> beParsedBy(InputParser& ip) = 0;
		virtual ~Input() {}
};

}

#endif 
