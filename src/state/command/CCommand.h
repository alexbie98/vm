#ifndef C_COMMAND_H
#define C_COMMAND_H

#include "state/command/Command.h"
#include "action/MovementAction.h"
#include "action/DeleteAction.h"

namespace vm {

class CCommand : public Command {

	private:
		std::unique_ptr<MovementAction> movement;
	public:
		CCommand(): Command{'c'} {}
		std::unique_ptr<Action> getAction(int key) override {
			

		}		
		~AtCommand() override {}
}

}

#endif
