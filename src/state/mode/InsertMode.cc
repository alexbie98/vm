#include "state/mode/InsertMode.h"
#include "state/mode/InsertModeInputParser.h"

using namespace std;
namespace vm {

InsertMode::InsertMode(): 
	Mode{make_unique<InsertModeInputParser>(), "INSERT"} {}
InsertMode::~InsertMode(){}

void InsertMode::onEnter(){} //TODO: diff tracking triggered here
void InsertMode::onExit(){}
void InsertMode::reset(){}
} 

