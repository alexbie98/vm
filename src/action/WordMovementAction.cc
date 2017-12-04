#include "action/WordMovementAction.h"
#include "data/Pos.h"
#include "state/State.h"
#include "state/File.h"
#include "state/CharIterator.h"

using namespace std;
namespace vm {


void WordMovementAction::doAction(State& context){
	
	Pos p = context.getFile().getCursorPos();

	for (auto it = context.getFile().MakeCharIterator(p);
			it!=context.getFile().charEnd();++it){
	//TODO
		
	}

}

WordMovementAction::WordMovementAction(size_t multi, 
		unique_ptr<Action> nextAction):
	Action{multi, move(nextAction)} {}
		
unique_ptr<Action> WordMovementAction::clone(){
	unique_ptr<Action> nextClone;
	if (nextAction) nextClone = nextAction->clone();
	return make_unique<WordMovementAction>(multi, move(nextClone));
}

WordMovementAction::~WordMovementAction() {}

}
