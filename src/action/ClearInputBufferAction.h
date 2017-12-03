#ifndef CLEAR_INPUT_BUFFER_ACTION_H
#define CLEAR_INPUT_BUFFER_ACTION_H
#include "action/Action.h"

namespace vm {

class ClearInputBufferAction : public Action {

	private:
		void doAction(State& context) override;

	public:
		ClearInputBufferAction(std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		~ClearInputBufferAction() override;

		std::unique_ptr<Action> clone() override;
};

}



#endif
