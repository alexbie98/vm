#ifndef KEY_INPUT_H
#define KEY_INPUT_H
#include "controller/Input.h"

namespace vm {

class KeyInput: public Input {
	private:
		char key;
	public:
		KeyInput(char cursesIn);
		~KeyInput() override;

		std::unique_ptr<Action> beParsedBy(InputParser& ip) override;
		char getKey();

};

}

#endif 
