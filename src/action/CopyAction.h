#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include "action/MovementModifiableAction.h"

namespace vm {


class CopyAction : public MovementModifiableAction {
	
	private:
		void performOp(State& context, Pos start, Pos end) override;

	public:
		CopyAction(std::unique_ptr<Action> movement
			 	= std::unique_ptr<Action>{},
				size_t multi = 1, 
				std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});

		std::unique_ptr<Action> clone() override;
		~CopyAction() override;
};


}

#endif 
