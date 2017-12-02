#ifndef MOVEMENT_MODIFIABLE_ACTION_H
#define MOVEMENT_MODIFIABLE_ACTION_H

#include "action/Action.h"
#include "data/Pos.h"

namespace vm {

class MovementAction;

class MovementModifiableAction : public Action {
	
	private:
		std::unique_ptr<MovementAction> movement;
		void doAction (State& context) override;
		virtual void performOp(State& context, Pos start, Pos end) = 0;

	public:
		MovementModifiableAction(std::unique_ptr<MovementAction> movement,
				size_t multi, std::unique_ptr<Action> nextAction);

		std::unique_ptr<MovementAction> getMovement();
		virtual ~MovementModifiableAction();

};


}

#endif 
