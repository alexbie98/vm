#ifndef KEY_INPUT_H
#define KEY_INPUT_H
#include "controller/Input.h"

namespace vm {

class KeyInput: public Input {
	private:
		int key;
	public:
		KeyInput(int cursesIn);
		~KeyInput() override;

		std::unique_ptr<Action> beParsedBy(InputParser& ip) override;
		int getKey();

};

}

#endif 
