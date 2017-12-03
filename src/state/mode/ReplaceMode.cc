#include "state/mode/ReplaceMode.h"
#include "ReplaceModeInputParser.h"

using namespace std;
namespace vm {

ReplaceMode::ReplaceMode(): 
	Mode{make_unique<ReplaceModeInputParser>(), "REPLACE"} {}
ReplaceMode::~ReplaceMode(){}

void ReplaceMode::onEnter(){} //TODO: diff tracking triggered here
void ReplaceMode::onExit(){}
void ReplaceMode::reset(){}
} 

