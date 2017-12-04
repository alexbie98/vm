#ifndef LINE_SEARCH_MOVEMENT_ACTION_H
#define LINE_SEARCH_MOVEMENT_ACTION_H

#include "action/Action.h"
namespace vm {

class LineSearchMovementAction : public Action {

	private:
		void doAction(State& context) override;
		bool forward;
		char search;
	public:
		LineSearchMovementAction(bool forward, char search,
				size_t multi = 1, std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		std::unique_ptr<Action> clone() override;
		~LineSearchMovementAction() override;

};

}



#endif
