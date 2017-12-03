#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include <stddef.h>

namespace vm {

class State;

class Action {


	private:
		virtual void doAction(State& context) = 0;
	
	protected:
		size_t multi;
		std::unique_ptr<Action> nextAction;

	public:
		Action(size_t multi, std::unique_ptr<Action> nextAction);
		void addNextAction(Action * next);
		void setMultiplier(size_t multi);
		size_t getMultiplier() const;
		void execute(State& context);
		virtual ~Action();
		virtual std::unique_ptr<Action> clone() = 0;
};

}


#endif
