#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include <stddef.h>

namespace vm {

class State;

class Action {

	private:
		size_t multiplier;
		std::unique_ptr<Action> nextAction;
		void executeOnce(State& context);
		virtual void doAction(State& context) = 0;
	public:
		void execute(State& context);
		virtual ~Action() = 0;
};

}


#endif
