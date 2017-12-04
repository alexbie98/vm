#include "action/WordMovementAction.h"
#include "data/Pos.h"
#include "state/State.h"
#include "state/File.h"
#include "state/CharIterator.h"
#include "util/Word.h"

using namespace std;
namespace vm {

int WordMovementAction::getType(char c){
	if (c>=48 && c<=57) return 1;
	if ((c>=65 && c<=90) || (c>=97 && c<=122)) return 2;
	if (c<=32) return 3;
	else return 4;
}

void WordMovementAction::doAction(State& context){
	
	Pos p = context.getFile().getCursorPos();
	const vector<string>& lines = context.getFile().getLines();
	int type;
	if (lines[p.y].size()!=0){
		type = getType(lines[p.y][p.x])	;
	}
	else {
		type = 4;
	}

	for (auto it = context.getFile().MakeCharIterator(p);
			it!=context.getFile().charEnd(); ++it){
			if (getType(*it)!=type && getType(*it)!=4){
				context.getFile().setCursorPos(it.getPos());		
			}
	}

}

WordMovementAction::WordMovementAction(size_t multi, 
		unique_ptr<Action> nextAction): Action{multi, move(nextAction)} {}
		
unique_ptr<Action> WordMovementAction::clone(){
	unique_ptr<Action> nextClone;
	if (nextAction) nextClone = nextAction->clone();
	return make_unique<WordMovementAction>(multi, move(nextClone));
}

WordMovementAction::~WordMovementAction() {}

}
