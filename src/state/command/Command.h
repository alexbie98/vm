#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "action/Action.h"
#include <unordered_map>

namespace vm {

class Command{
	
	private:
		int name;
		bool isMovementCommand;
	public:
		Command(int name, bool isMovementCommand=false): name{name},
			isMovementCommand{isMovementCommand} {}
		virtual std::unique_ptr<Action> getAction(int key = 0, 
				std::unordered_map<int,std::unique_ptr<Command>>* const map =
				nullptr) = 0;
		bool isMovement() { return isMovementCommand; }
		bool operator==(const Command& other){ return name == other.name; }
		virtual ~Command() {}
};

}

#endif
