#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

namespace vm {

class Action;

class Command{
	private:
		char name;
	public:
		Command(char name) name{name} {}
		virtual std::unique_ptr<Action> getAction(Command* c);
		bool operator==(const Command& other){ return name == other.name; }
		virtual ~Command() {}
}

}

#endif
