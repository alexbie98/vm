#ifndef	RUN_MACRO_ACTION_H
#define RUN_MACRO_ACTION_H

#include "action/Action.h"

namespace vm {

class RunMacroAction : public Action {

	private:
		void doAction(State& context) override;
		int key;
	public:
		RunMacroAction(int key, size_t multi = 1, 
				std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});
		std::unique_ptr<Action> clone() override;
		~RunMacroAction() override;
};

}



#endif
