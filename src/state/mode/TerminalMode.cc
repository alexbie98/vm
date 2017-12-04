#include "state/mode/TerminalMode.h"
#include "state/mode/TerminalModeInputParser.h"

using namespace std;
namespace vm {

TerminalMode::TerminalMode():
	Mode{make_unique<TerminalModeInputParser>(),"TERMINAL"} {}

TerminalMode::~TerminalMode(){}
void TerminalMode::onEnter(){}
void TerminalMode::onExit(){}
void TerminalMode::reset() {}
const std::string& TerminalMode::getCommandBuffer() const{return "Terminal bufffer placeholder";}
}
