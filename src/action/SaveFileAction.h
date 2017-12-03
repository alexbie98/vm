#ifndef SAVE_FILE_ACTION_H
#define SAVE_FILE_ACTION_H

#include "action/Action.h"

namespace vm {

class SaveFileAction : public Action {

	private:
		void doAction(State& context) override;

	public:
		SaveFileAction(std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		std::unique_ptr<Action> clone() override;
		~SaveFileAction() override;
};

}



#endif
