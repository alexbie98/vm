#ifndef INSERT_MODE_H
#define INSERT_MODE_H

#include "state/mode/Mode.h"

namespace vm {

class InsertMode : public Mode {

	private:
		std::unique_ptr<Action> cumulativeAction;
	public:
		InsertMode();
		~InsertMode();

		void onEnter() override;
		void onExit() override;
		void reset() override;
};

}

#endif
