#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "action/Action.h"

namespace vm {

class Command{
	
	private:
		char name;
		bool isMovementCommand;
	public:
		Command(char name, bool isMovementCommand=false): name{name},
			isMovementCommand{isMovementCommand} {}
		virtual std::unique_ptr<Action> getAction(char key);
		bool isMovement() { return isMovementCommand; }
		bool operator==(const Command& other){ return name == other.name; }
		virtual ~Command() {}
};

}

#endif
