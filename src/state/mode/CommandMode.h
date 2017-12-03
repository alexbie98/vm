#ifndef COMMAND_MODE_H
#define COMMAND_MODE_H

#include "state/mode/Mode.h"

namespace vm {

class CommandMode : public Mode {

	public:
		CommandMode();
		~CommandMode() override;

		void onEnter() override;
		void onExit() override;
		void reset() override;
};

}

#endif
