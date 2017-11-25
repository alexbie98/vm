#ifndef STATE_H
#define STATE_H

#include <string>
#include "StateViewable.h"
#include "data/Event.h"
#include "data/Subject.h"
#include "controller/Input.h"
namespace vm {

class State: public StateViewable, public Subject<State,Event> {

public:
  void addFile(const std::string& file){};
  bool isValid(){};
  void handleInput(Input* input){};
};

}


#endif
