#ifndef D_COMMAND_H
#define D_COMMAND_H

#include "state/command/Command.h"

namespace vm {

class DCommand : public Command {

	private:
		char macroKey;
	public:
		AtCommand(char macroKey) macroKey{macroKey} {}
		std::unique_ptr<Action> getAction(char key) override {
			return unique_ptr<Action>{};
		}		
		~AtCommand() override {}
}

}

#endif
