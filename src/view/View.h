#ifndef VIEW_H
#define VIEW_H
#include "data/Event.h"
#include "state/State.h"

namespace vm {

class View : public Observer<State, Event> {

	public:
		virtual ~View() {}

};

}

#endif
