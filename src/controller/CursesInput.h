#ifndef CURSES_INPUT_H
#define CURSES_INPUT_H
#include "controller/Input.h"

namespace vm {

class CursesInput: public Input {
	private:
		char cursesIn;
	public:
		CursesInput(char cursesIn);
		~CursesInput() override;

		std::unique_ptr<Action> beParsedBy(InputParser& ip) override;
		char getCursesIn();

};

}

#endif 
