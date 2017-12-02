#ifndef SIMPLE_COMMAND_H
#define SIMPLE_COMMAND_H

#include "state/command/Command.h"

namespace vm {
class SimpleCommand : Command {

	private:
		std::unique_ptr<Action> a;

	public:
		SimpleCommand(char name, std::unique_ptr<Action> a): 
			Command{name}, a{std::move(a)} {}

		std::unique_ptr<Action> getAction(char key=0) override {
			return std::move(a);
		}
		~SimpleCommand() override{}
};

}











#endif
