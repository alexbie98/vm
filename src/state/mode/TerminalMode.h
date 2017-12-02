#ifndef TERMINAL_MODE_H
#define TERMINAL_MODE_H

#include "state/mode/Mode.h"

namespace vm {

class TerminalMode : public Mode {

	public:
		TerminalMode();
		~TerminalMode();

		void onEnter();
		void onExit();
};

}

#endif