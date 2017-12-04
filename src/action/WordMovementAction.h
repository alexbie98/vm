#ifndef WORD_MOVEMENT_ACTION_H
#define WORD_MOVEMENT_ACTION_H

#include "action/Action.h"

namespace vm {

class WordMovementAction : public Action{

	private:
		void doAction(State& context) override;

	public:
		WordMovementAction(size_t multi = 1, 
				std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});
		
		std::unique_ptr<Action> clone() override;
		~WordMovementAction() override;

};

}


#endif
