#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include <stddef.h>

namespace vm {

class State;

class Action {


	private:
		size_t multi;
		virtual void doAction(State& context) = 0;
	
	protected:
		std::unique_ptr<Action> nextAction;

	public:
		Action(size_t multi, std::unique_ptr<Action> nextAction);
		void setMultiplier(size_t multi);
		size_t getMultiplier() const;
		void execute(State& context);
		virtual ~Action();
		virtual std::unique_ptr<Action> clone() = 0;
};

}


#endif
