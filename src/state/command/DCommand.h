#ifndef D_COMMAND_H
#define D_COMMAND_H

#include "state/command/Command.h"

namespace vm {

class MovementAction;
class Action;

class DCommand : public Command {

	public:
		DCommand();
		std::unique_ptr<Action> getAction(int key, 
			std::map<int,Command*>* const map) override;
		~DCommand() override;
};

}

#endif
