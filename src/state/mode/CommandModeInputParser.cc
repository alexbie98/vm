#include "state/mode/CommandModeInputParser.h"
#include "state/command/Command.h"
#include "state/command/SimpleCommand.h"
#include "state/command/AtCommand.h"
#include "state/command/DCommand.h"
#include "state/command/CCommand.h"

#include "controller/KeyInput.h"
#include "action/Action.h"
#include "action/DirectionalMovementAction.h"
#include "action/ChangeModeAction.h"
#include "action/DeleteAction.h"
#include "action/WordMovementAction.h"


#include "state/mode/InsertMode.h"
#include "state/mode/TerminalMode.h"
#include "state/mode/ReplaceMode.h"
#include <utility>
#include "data/Direction.h"

#include <iostream>
using namespace std;
namespace vm {

void CommandModeInputParser::reset(){
	numBuffer = 0;
	multiplier = 1;
	current = nullptr;

}		

void CommandModeInputParser::addEntries(){
	
	a = make_unique<SimpleCommand>('a',false, 
		 make_unique<ChangeModeAction>(typeid(InsertMode),0,
		    make_unique<DirectionalMovementAction>(RIGHT)));

	c = make_unique<CCommand>();
	d = make_unique<DCommand>();
	
	//f = make_unique<FCommand>();
	
	
	i = make_unique<SimpleCommand>('i', false,
		make_unique<ChangeModeAction>(typeid(InsertMode)));

	h = make_unique<SimpleCommand>('h', true,
		make_unique<DirectionalMovementAction>(LEFT));

	j = make_unique<SimpleCommand>('h', true,
		make_unique<DirectionalMovementAction>(UP));

	k = make_unique<SimpleCommand>('k', true,
		make_unique<DirectionalMovementAction>(DOWN));

	l = make_unique<SimpleCommand>('l', true,
		make_unique<DirectionalMovementAction>(RIGHT));
	
	w = make_unique<SimpleCommand>('w', true,
		make_unique<WordMovementAction>());
	
	slash = make_unique<SimpleCommand>('/', false,
		make_unique<ChangeModeAction>(typeid(TerminalMode),'/'));
	
	question = make_unique<SimpleCommand>('?', false,
		make_unique<ChangeModeAction>(typeid(TerminalMode),'?'));
	
	colon = make_unique<SimpleCommand>(':', false,
		make_unique<ChangeModeAction>(typeid(TerminalMode),':'));

	commandMap['a'] = a.get();
	commandMap['c'] = c.get();
	commandMap['d'] = d.get();
	commandMap['i'] = i.get();
	commandMap['h'] = h.get();
	commandMap['j'] = j.get();
	commandMap['k'] = k.get();
	commandMap['l'] = l.get();
	commandMap['/'] = slash.get();
	commandMap['?'] = question.get();
	commandMap[':'] = colon.get();

}

CommandModeInputParser::CommandModeInputParser(): numBuffer{0},
	multiplier{1}, current{nullptr} {
	addEntries();
}


unique_ptr<Action> CommandModeInputParser::parseInput(KeyInput* in){
	int key = in->getKey();
	
	cout << numBuffer<< endl;
	if (current == nullptr) {
		if (key >=48 && key<=57){
			numBuffer = numBuffer*10 + (key-48);
			return unique_ptr<Action>();
		}
		else if(commandMap.count(key)){
			current = commandMap[key];
			multiplier*=(numBuffer ? numBuffer : 1);
			if (dynamic_cast<SimpleCommand*>(current)){
				Action * act = current->getAction().release();
				act->setMultiplier(numBuffer);
				reset();
				return unique_ptr<Action>{act};
			}
			else{
				return unique_ptr<Action>{};
			}
		}
		else{
			reset();
			return unique_ptr<Action>{};
		}
	}
	else {
		if //(dynamic_cast<RCommand*>(current) ||
				( dynamic_cast<AtCommand *>(current)){
			multiplier*=(numBuffer ? numBuffer : 1);
			Action * act = current->getAction(key, &commandMap).release();
			act->setMultiplier(multiplier);
			reset();
			return unique_ptr<Action>{act};
		}
		else if (key >=48 && key<=57){
			numBuffer = numBuffer*10 + (key-48);
			return unique_ptr<Action>();
		}
		else {
			multiplier*=(numBuffer ? numBuffer : 1);
			Action * act = current->getAction(key, &commandMap).release();
			act->setMultiplier(multiplier);
			reset();
			return unique_ptr<Action>(act);
		}
	}

}

CommandModeInputParser::~CommandModeInputParser(){}



}

