#ifndef FILE_SEARCH_MOVEMENT_ACTION_H
#define FILE_SEARCH_MOVEMENT_ACTION_H

#include "action/Action.h"
#include <string>
namespace vm {

class FileSearchMovementAction : public Action {

	private:
		void doAction(State& context) override;
		bool forward;
		std::string searchStr;
	public:
		FileSearchMovementAction(bool forward, std::string searchStr,
				size_t multi = 1, std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		std::unique_ptr<Action> clone() override;
		~FileSearchMovementAction() override;

};

}



#endif
