#ifndef MOVEMENT_MODIFIABLE_ACTION_H
#define MOVEMENT_MODIFIABLE_ACTION_H

#include "action/Action.h"
#include "data/Pos.h"

namespace vm {

class MovementModifiableAction : public Action {
	protected:
		std::unique_ptr<Action> movement;
	private:
		void doAction (State& context) override;
		virtual void performOp(State& context, Pos start, Pos end) = 0;

	public:
		MovementModifiableAction(std::unique_ptr<Action> movement,
				size_t multi, std::unique_ptr<Action> nextAction);
		virtual ~MovementModifiableAction();

};


}

#endif 
