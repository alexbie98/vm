#include "controller/CursesController.h"
#include "controller/KeyInput.h"

using namespace std;

namespace vm {

CursesController::CursesController(curses::CursesInstance& cInst): 
	cInst{cInst} {}

CursesController::~CursesController() {}

unique_ptr<Input> CursesController::getInput(){
	char c = cInst.getCh();
	return make_unique<KeyInput>(c);
}




}
