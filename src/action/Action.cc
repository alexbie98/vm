#include "action/Action.h"

using namespace std;

namespace vm {

Action::Action(size_t multi, unique_ptr<Action> nextAction):
	multi{multi}, nextAction{move(nextAction)} {}

void Action::execute(State& context){
	for (size_t i=0;i<multi;i++){
		doAction(context);
	}
	if (nextAction) nextAction->execute(context);
}
void Action::setMultiplier(size_t multi){
	this->multi = multi;
}

size_t Action::getMultiplier() const{
	return multi;
}

void Action::addNextAction(Action * newAction){
	if (!nextAction) {
		nextAction = unique_ptr<Action>{newAction};
	}
	else nextAction->addNextAction(newAction);
}

Action::~Action(){}

}
