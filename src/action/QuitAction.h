#ifndef QUIT_ACTION_H
#define QUIT_ACTION_H

#include "action/Action.h"

namespace vm {

class QuitAction : public Action {

	private:
		void doAction(State& context) override;

	public:
		QuitAction(std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		std::unique_ptr<Action> clone() override;
		~QuitAction() override;

};

}



#endif
