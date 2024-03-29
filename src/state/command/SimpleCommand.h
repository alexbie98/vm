#ifndef SIMPLE_COMMAND_H
#define SIMPLE_COMMAND_H

#include "state/command/Command.h"

namespace vm {
	class SimpleCommand : public Command {

	private:
		std::unique_ptr<Action> a;

	public:
		SimpleCommand(int name, bool isMovementCommand, std::unique_ptr<Action> a): 
			Command{name, isMovementCommand}, a{std::move(a)} {}

		std::unique_ptr<Action> getAction(int key = 0,
				std::map<int,Command*>* const map = nullptr)  override {
			return a->clone();
		}
		~SimpleCommand() override{}
};

}


#endif
