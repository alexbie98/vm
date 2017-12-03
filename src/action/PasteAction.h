#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H

#include "action/Action.h"

namespace vm {

class PasteAction : public Action {

	private:
		void doAction(State& context) override;

	public:
		PasteAction(size_t multi = 1, std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		~PasteAction() override;
};

}



#endif
