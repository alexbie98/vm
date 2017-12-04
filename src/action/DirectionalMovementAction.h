#ifndef DIRECTIONAL_MOVEMENT_ACTION_H
#define DIRECTIONAL_MOVEMENT_ACTION_H

#include "action/Action.h"
#include "data/Direction.h"

namespace vm {

class DirectionalMovementAction : public Action{

	private:
		Direction d;
		void doAction(State& context) override;

	public:
		DirectionalMovementAction(Direction d, size_t multi = 1,
			std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});
		
		~DirectionalMovementAction() override;
		std::unique_ptr<Action> clone() override;

};

}


#endif
