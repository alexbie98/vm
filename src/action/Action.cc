#include "action/Action.h"
#include "state/State.h"

namespace vm {

void Action::executeOnce(State& context){
	doAction(context);
	nextAction->execute(context);
}

void Action::execute(State& context){
	for (size_t i=0; i<multiplier;i++){
		executeOnce(context);
	}	
}

}
