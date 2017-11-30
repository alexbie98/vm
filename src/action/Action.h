#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include <stddef.h>

namespace vm {

class State;

class Action {

	protected:
		std::unique_ptr<Action> nextAction;

	private:
		size_t multi;
		virtual void doAction(State& context) = 0;

	public:
		Action(size_t multi = 1,
				std::unique_ptr<Action> nextAction=unique_ptr<Action>{});
		void setMultiplier(size_t multi);
		size_t getMultiplier() const;
		void execute(State& context);
		virtual ~Action();
		virtual std::unique_ptr<Action> clone() = 0;
};

}


#endif
