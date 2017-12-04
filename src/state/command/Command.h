#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "action/Action.h"
#include <map>

namespace vm {

class Command{
	
	private:
		int name;
		bool isMovementCommand;
	public:
		Command(int name, bool isMovementCommand=false): name{name},
			isMovementCommand{isMovementCommand} {}
		virtual std::unique_ptr<Action> getAction(int key = 0, 
				std::map<int,Command*>* const map = nullptr) = 0;
		bool isMovement() { return isMovementCommand; }
		bool operator==(const Command& other){ return name == other.name; }
		virtual ~Command() {}
};

}

#endif
