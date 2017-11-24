#ifndef INPUT_H
#define INPUT_H

namespace vm {

// forward declare
class InputParser;

class Input {
	
	virtual void beParsedBy(InputParser ip) = 0;

};

}

#endif 
