#ifndef View_H
#define View_H
#include "data/Event"
#include "state/State.h"

namespace vm {

class View : public Observer<State, Event> {


};

}

#endif
