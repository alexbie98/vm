#ifndef DELETE_ACTION_H
#define DELETE_ACTION_H

#include "action/MovementModifiableAction.h"
#include "action/DirectionalMovementAction.h"

namespace vm {


class DeleteAction : public MovementModifiableAction {
	
	private:
		void performOp(State& context, Pos start, Pos end) override;

	public:
		DeleteAction(std::unique_ptr<MovementAction> movement
			 	= std::make_unique<DirectionalMovementAction>(LEFT),
				size_t multi = 1, 
				std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});
		
		std::unique_ptr<Action> clone() override;
		~DeleteAction() override;
};


}

#endif 
