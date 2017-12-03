#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "action/Action.h"

namespace vm {

class Command{
	
	private:
		int name;
		bool isMovementCommand;
	public:
		Command(int name, bool isMovementCommand=false): name{name},
			isMovementCommand{isMovementCommand} {}
		virtual std::unique_ptr<Action> getAction(int key);
		bool isMovement() { return isMovementCommand; }
		bool operator==(const Command& other){ return name == other.name; }
		virtual ~Command() {}
};

}

#endif
