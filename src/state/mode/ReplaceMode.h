#ifndef REPLACE_MODE_H
#define REPLACE_MODE_H

#include "state/mode/Mode.h"

namespace vm {

class ReplaceMode : public Mode {

	private:
		std::unique_ptr<Action> cumulativeAction;
	public:
		ReplaceMode();
		~ReplaceMode();

		void onEnter() override;
		void onExit() override;
		void reset() override;
};

}

#endif
