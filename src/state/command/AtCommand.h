#ifndef AT_COMMAND_H
#define AT_COMMAND_H

#include "state/command/Command.h"

namespace vm {

class AtCommand : public Command {

	private:
		int macroKey;
	public:
		AtCommand(int macroKey): Command{'@'}, macroKey{macroKey} {}
		std::unique_ptr<Action> getAction(int key) override {
			return unique_ptr<Action>{};
		}
		~AtCommand() override {}
}

}

#endif
