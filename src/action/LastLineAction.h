#ifndef LAST_LINE_ACTION_H
#define LAST_LINE_ACTION_H

#include "action/Action.h"

namespace vm {

class LastLineAction : public Action {

	private:
		void doAction(State& context) override;

	public:
		LastLineAction(std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		std::unique_ptr<Action> clone() override;
		~LastLineAction() override;

};

}



#endif
