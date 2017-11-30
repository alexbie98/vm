#include "action/DirectionalMovementAction.h"
#include "state/State.h"
#include "state/File.h"
#include <memory>

using namespace std;
namespace vm {

void DirectionalMovementAction::doAction(State& context){
 Pos p;

 switch(d){
	case UP: p.y++; break;
	case DOWN: p.y--; break;
	case LEFT: p.x--; break;
	case RIGHT: p.x++; break;
 }
 Pos current = context.getFile().getCursorPos();
 context.getFile().setCursorPos(current+=p);
}

DirectionalMovementAction::DirectionalMovementAction(Direction d,
		size_t multi, unique_ptr<Action> nextAction):
	Action{multi, move(nextAction)}, d{d} {}
		
unique_ptr<Action> DirectionalMovementAction::clone(){
	unique_ptr<Action> nextClone;
	if (nextAction)  
	return make_unique<Action>(d, multi, nextAction->clone());

}
DirectionalMovementAction::~DirectionalMovementAction() {}

}
