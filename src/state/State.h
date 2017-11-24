#ifndef STATE_H
#define STATE_H

#include "state/StateViewable.h"
#include "data/Event.h"
#include "data/Subject.h"
namespace vm {

class State: public StateViewable, public Subject<State,Event> {


};

}


#endif
