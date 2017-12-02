#ifndef AT_COMMAND_H
#define AT_COMMAND_H

#include "state/command/Command.h"

namespace vm {

class AtCommand : public Command {

	private:
		char macroKey;
	public:
		AtCommand(char macroKey): Command{'@'}, macroKey{macroKey} {}
		std::unique_ptr<Action> getAction(char key) override {
			return unique_ptr<Action>{};
		}
		~AtCommand() override {}
}

}

#endif
