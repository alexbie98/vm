#ifndef TEXT_CHANGE_ACTION_H
#define TEXT_CHANGE_ACTION_H

#include "action/Action.h"

namespace vm {

class TextChangeAction: public Action {

	public:
		TextChangeAction(size_t multi, std::unique_ptr<Action> nextAction):
			Action{multi, std::move(nextAction)} {}

		virtual ~TextChangeAction() override {}

};

}


#endif
