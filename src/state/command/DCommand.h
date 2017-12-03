#ifndef D_COMMAND_H
#define D_COMMAND_H

#include "state/command/Command.h"

namespace vm {

class DCommand : public Command {

	private:
		int macroKey;
	public:
		AtCommand(int macroKey) macroKey{macroKey} {}
		std::unique_ptr<Action> getAction(int key) override {
			return unique_ptr<Action>{};
		}		
		~AtCommand() override {}
}

}

#endif
