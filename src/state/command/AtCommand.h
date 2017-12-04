#ifndef AT_COMMAND_H
#define AT_COMMAND_H

#include "state/command/Command.h"

namespace vm {

class AtCommand : public Command {

	public:
		AtCommand();
		std::unique_ptr<Action> getAction(int key, 
				std::map<int,Command*>* const map = nullptr) override;

		~AtCommand() override;
};

}

#endif
