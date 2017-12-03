#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H

#include "action/TextChangeAction.h"

namespace vm {

class PasteAction : public TextChangeAction {

	private:
		void doAction(State& context) override;

	public:
		PasteAction(size_t multi = 1, std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});

		std::unique_ptr<Action> clone() override;
		~PasteAction() override;
};

}



#endif
