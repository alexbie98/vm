#include "controller/CursesController.h"
#include "controller/KeyInput.h"

using namespace std;

namespace vm {

CursesController::CursesController(curses::CursesInstance& cInst): 
	cInst{cInst} {}

CursesController::~CursesController() {}

unique_ptr<Input> CursesController::getInput(){
	int c = cInst.getChar();
	return make_unique<KeyInput>(c);
}




}
