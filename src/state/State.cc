#include "state/State.h"
#include "action/Action.h"
#include "state/File.h"
#include "state/mode/Mode.h"
#include "state/mode/CommandMode.h"
#include "state/mode/InsertMode.h"
#include "state/mode/ReplaceMode.h"
#include "state/mode/TerminalMode.h"
#include "controller/Input.h"
#include "util/FileReader.h"
#include "util/FileWriter.h"
#include "state/SyntaxHighlighter.h"
#include "state/DictionaryAttribute.h"
#include <vector>
#include <string>
#include "state/SyntaxConstants.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace vm {

const int State::RUNNING = 1;
const int State::SAFE_EXIT = 0;
const int State::ERROR_EXIT = 2;

State::State(): runStatus{RUNNING}, commandMode{new CommandMode()},
	insertMode{new InsertMode()}, replaceMode{new ReplaceMode()}, 
	terminalMode{new TerminalMode()}, buildingMacro{false} {
		initExtHighlighters();
		activeMode = insertMode.get();
	}

State::~State(){}

void State::initExtHighlighters(){

	unique_ptr<SyntaxHighlighter> cpp = make_unique<SyntaxHighlighter>();

	// Add range and word attributes
	cpp->rangeAttributes.push_back(RangeAttribute(syntax::DoubleQuotes, "\"", "\""));

	DictionaryAttribute keyword(1, syntax::Keyword);//TODO make precedence constants
	for(const string &s: syntax::Keywords) keyword.addKey(s);

	// Add Syntax highlighters to buffer
	syntaxHighlighters.push_back(std::move(cpp));

	// Correspond file extensions with respective syntax highlighters
	extHighlighters[".cc"] = syntaxHighlighters[0].get();
	extHighlighters[".h"] = syntaxHighlighters[0].get();
}

void State::addFile(const std::string& file){
	util::FileReader reader;
	files.push_back(make_unique<File>(file, reader.readLines(file)));
	if (files.size()==1){
		activeFile = files[0].get();
	}

	// Set files syntax highlighter if it has one for its extension
	auto s = extHighlighters.find(files.back()->getFileExtension());
	if(!(s == extHighlighters.end())) files.back()->setSyntaxHighlighter((*s).second);
	else files.back()->setSyntaxHighlighter(nullptr);

	notifyAll(FILE_ADDED);
}

void State::saveActiveFile(){
	util::FileWriter writer;
	writer.writeLines(activeFile->getName(), activeFile->getLines());
}

void State::setRunStatus(int runStatus) {
	this->runStatus = runStatus;
}

int State::getRunStatus() const{
	return runStatus;
}

void State::handleInput(unique_ptr<Input> input){
	std::unique_ptr<Action> action = activeMode->parseInput(input.get());
	if (action){
		cout << "action triggered!" << endl;
		try {
			action->execute(*this);
		} catch(...){}
	}
	notifyAll(ACTION_EXECUTED);
}


File& State::getFile() {
	return *activeFile;
}

const File& State::getFile() const {
	return *activeFile;
}

void State::setActiveMode(const type_info& nextMode){
	activeMode->onExit();

	if (nextMode == typeid(CommandMode)) activeMode = commandMode.get();
	else if (nextMode == typeid(InsertMode)) activeMode = insertMode.get();
	else if (nextMode == typeid(ReplaceMode)) activeMode = replaceMode.get();
	else if (nextMode == typeid(TerminalMode)) activeMode = terminalMode.get();
	else throw;

	activeMode->onEnter();
}

Mode& State::getMode(){
	return *activeMode;
}


// Register functions -----------------
State::Register& State::getRegister() {
	return reg;
}

State::Register::Register(): paste{}, strSearch{}, charSearch{0},
 lastChangeAction{}, macroMap{}, scrollLength{0} {}

void State::startNewMacro(){
	buildingMacro = true;
}

unique_ptr<Action> State::saveCurrentMacro(){
	buildingMacro = false;
	return move(reg.currentMacro);

}

}
