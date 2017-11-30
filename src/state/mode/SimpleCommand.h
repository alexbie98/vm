#ifndef SIMPLE_COMMAND_H
#define SIMPLE_COMMAND_H

#include "state/mode/Command.h"

namespace vm {
class SimpleCommand : Command {

	private:
		std::unique_ptr<Action> a;

	public:
		SimpleCommand(char name, std::unique_ptr<Action> a): 
			Command{name}, a{std::move(a)} {}
		std::unique_ptr<Action> getAction(Command* c = nullptr) override {
			return a;
		}
		~Command() {}
};

}











#endif
