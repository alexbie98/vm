#ifndef CHANGE_MODE_ACTION_H
#define CHANGE_MODE_ACTION_H

#include "action/Action.h"

namespace vm {

class Mode;

class ChangeModeAction : public Action {

	private:
		void doAction(State& context) override;
		const std::type_info& nextMode;
		char in;
	public:
		ChangeModeAction(const std::type_info& nextMode, char in = 0,
				std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});
		~ChangeModeAction() override;
		std::unique_ptr<Action> clone() override;

};

}



#endif
