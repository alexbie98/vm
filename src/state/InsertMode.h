#ifndef INSERT_MODE_H
#define INSERT_MODE_H

#include "state/Mode.h"

namespace vm {

class InsertMode : public Mode {

	public:
		InsertMode();
		~InsertMode();

		void onEnter();
		void onExit();
};

}

#endif
