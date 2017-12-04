#include "state/mode/TerminalMode.h"
#include "state/mode/TerminalModeInputParser.h"

using namespace std;
namespace vm {

TerminalMode::TerminalMode():
	Mode{make_unique<TerminalModeInputParser>(),"TERMINAL"} {}

TerminalModeInputParser* TerminalMode::getTerminalParser(){
	return dynamic_cast<TerminalModeInputParser*>(getParser());
}

const TerminalModeInputParser* TerminalMode::getTerminalParser()const{
	return dynamic_cast<const TerminalModeInputParser*>(getParser());
}

TerminalMode::~TerminalMode(){}
void TerminalMode::onEnter(){}
void TerminalMode::onExit(){
	reset();
}

void TerminalMode::reset(){
	getTerminalParser()->reset();
}


}
