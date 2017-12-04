#include "state/mode/TerminalModeInputParser.h"
#include "controller/KeyInput.h"
#include "action/Action.h"
#include "action/ChangeModeAction.h"
#include "state/mode/CommandMode.h"
#include "action/SaveFileAction.h"

#include "action/QuitAction.h"
#include "action/LastLineAction.h"
#include "action/FileSearchMovementAction.h"
#include <ncurses.h>

using namespace std;

namespace vm {

TerminalModeInputParser::TerminalModeInputParser(): cursor{0} {}

unique_ptr<Action> TerminalModeInputParser::parseInput(KeyInput* in){
	int key = in->getKey();

	switch (key){
		// ASCII 27 = esc key
		case 27: return make_unique<ChangeModeAction>(typeid(CommandMode));
		case KEY_LEFT: if (cursor!=0) cursor--; break;
		case KEY_RIGHT:if (cursor!=commandBuffer.size()) cursor++; break;
		case KEY_ENTER: {
			if (commandBuffer == ":w") return make_unique<SaveFileAction>();
			else if (commandBuffer == ":q!") return make_unique<QuitAction>();
			//else if(commmandBuffer == ":r")
			else if (commandBuffer == ":$") return make_unique<LastLineAction>(
					make_unique<ChangeModeAction>(typeid(CommandMode)));
			else if (commandBuffer[0] == '/') {
				return make_unique<FileSearchMovementAction>(true,
						commandBuffer.substr(1), 1,
						make_unique<ChangeModeAction>(typeid(CommandMode)));
			}
			else if (commandBuffer[0] == '?') {
				return make_unique<FileSearchMovementAction>(false,
						commandBuffer.substr(1), 1,
						make_unique<ChangeModeAction>(typeid(CommandMode)));
			}
		}
		case KEY_BACKSPACE: {
			delCh();
			if (commandBuffer.size() == 0){
				return make_unique<ChangeModeAction>(typeid(CommandMode));
			}
		}
		default: {
			if (key>=32 && key<=126){ //needs to go in helper
				addCh(key);
			}
			else return unique_ptr<Action>{};
		}
	}

	return unique_ptr<Action>();
}

void TerminalModeInputParser::addCh(char c){
	commandBuffer.insert(cursor+1, string(1,c));
	cursor++;
}
void TerminalModeInputParser::delCh(){
	if (cursor == 0) return;
	else commandBuffer.erase(cursor-1,1);
	cursor--;	
}


string TerminalModeInputParser::getCommandBuffer() const {
	return commandBuffer;
}

void TerminalModeInputParser::setCommandBuffer(std::string s){
	commandBuffer = s;
	cursor = s.size();
}

size_t TerminalModeInputParser::getCursorPos() const{
	return cursor;
}

void TerminalModeInputParser::reset(){
	commandBuffer = "";
	cursor = 0;
}		

TerminalModeInputParser::~TerminalModeInputParser(){}

}
