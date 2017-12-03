#ifndef INSERTION_ACTION_H
#define INSERTION_ACTION_H

#include "action/TextChangeAction.h"
#include <string>

namespace vm {

class InsertionAction : public TextChangeAction {

	private:
		std::string toInsert;
		void doAction(State& context) override;

	public:
		InsertionAction(const std::string& toInsert, size_t multi = 1,
				std::unique_ptr<Action> nextAction = std::unique_ptr<Action>{});

		std::unique_ptr<Action> clone() override;
		~InsertionAction() override;
};

}



#endif
