#ifndef C_COMMAND_H
#define C_COMMAND_H

#include "state/command/Command.h"

namespace vm {

class Action;

class CCommand : public Command {

	public:
		CCommand();
		std::unique_ptr<Action> getAction(int key, 
				std::map<int, Command*>* const map) override;
		~CCommand() override;
};

}

#endif
