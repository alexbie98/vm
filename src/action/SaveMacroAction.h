#ifndef	SAVE_MACRO_ACTION_H
#define SAVE_MACRO_ACTION_H

#include "action/Action.h"

namespace vm {

class SaveMacroAction : public Action {

	private:
		void doAction(State& context) override;
		int key;
	public:
		SaveMacroAction(int key, 
				std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});
		std::unique_ptr<Action> clone() override;
		~SaveMacroAction() override;
};

}



#endif
