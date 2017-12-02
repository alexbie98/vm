#ifndef MOVEMENT_ACTION_H
#define MOVEMENT_ACTION_H

#include "action/Action.h"

namespace vm {

class MovementAction: public Action {

	public:
		MovementAction(size_t multi, std::unique_ptr<Action> nextAction):
			Action{multi, std::move(nextAction)} {}

		virtual ~MovementAction() override {}

};

}


#endif
