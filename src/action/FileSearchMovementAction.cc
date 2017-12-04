#include "action/FileSearchMovementAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void FileSearchMovementAction::doAction(State& context) {
	
	File& f = context.getFile();
	const vector<string>& lines = f.getLines();
	if (forward){
		size_t found = 
			lines[f.getCursorPos().y].find(searchStr, f.getCursorPos().x);
		if (found!= string::npos) {
			f.setCursorPos(Pos{found,f.getCursorPos().y});
			return;
		}
		size_t y = f.getCursorPos().y;
		size_t located;
		y++;
		while (y!=lines.size()){
			located = lines[y].find(searchStr);
			if (located!= string::npos) {
				f.setCursorPos(Pos{located,y});
				return;
			}
			y++;
		}
	}

	else {
		size_t found = 
			lines[f.getCursorPos().y].rfind(searchStr, f.getCursorPos().x);
		if (found!= string::npos) {
			f.setCursorPos(Pos{found,f.getCursorPos().y});
			return;
		}
		size_t y = f.getCursorPos().y;
		size_t located;
		y--;
		while (y!=string::npos){
			located = lines[y].rfind(searchStr);
			if (located!= string::npos) {
				f.setCursorPos(Pos{located,y});
				return;
			}
			y--;
		}
	}
}

FileSearchMovementAction::FileSearchMovementAction(bool forward, string 
		searchStr, size_t multi, unique_ptr<Action> nextAction):
	Action{multi,move(nextAction)}, forward{forward}, 
	searchStr{move(searchStr)} {}

unique_ptr<Action> FileSearchMovementAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<FileSearchMovementAction>(forward, 
			searchStr, multi,move(nextClone));
}

FileSearchMovementAction::~FileSearchMovementAction() {}

}

