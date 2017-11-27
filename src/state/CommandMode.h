#ifndef COMMAND_MODE_H
#define COMMAND_MODE_H

#include "state/Mode.h"

namespace vm {

class CommandMode : public Mode {

	public:
		CommandMode();
		~CommandMode();

		void onEnter();
		void onExit();
};

}

#endif
