#include "state/State.h"
#include "action/Action.h"
#include "state/File.h"
#include "state/mode/Mode.h"
#include "state/mode/CommandMode.h"
#include "state/mode/InsertMode.h"
#include "state/mode/TerminalMode.h"
#include "controller/Input.h"
#include "util/FileReader.h"
#include "util/FileWriter.h"
#include "state/SyntaxHighlighter.h"
#include "state/DictionaryAttribute.h"
#include <vector>
#include <string>
#include "state/SyntaxConstants.h"

using namespace std;

namespace vm {

const int State::RUNNING = 1;
const int State::SAFE_EXIT = 0;
const int State::ERROR_EXIT = 2;

State::State(): runStatus{RUNNING}, commandMode{new CommandMode()},
	insertMode{new InsertMode()}, terminalMode{new TerminalMode()} {
		//Init highlighter extension map
		initExtHighlighters();
	}

State::~State(){}

void State::initExtHighlighters(){
	unique_ptr<SyntaxHighlighter> cpp = make_unique<SyntaxHighlighter>(SyntaxHighlighter());

	// Add range and word attributes
	cpp->rangeAttributes.push_back(RangeAttribute(syntax::DoubleQuote, "\"", "\""));
	cpp->rangeAttributes.push_back(RangeAttribute(syntax::MultiLineComment, "/*", "*/"));

	std::unique_ptr<DictionaryAttribute> keywordAttribute =
		make_unique<DictionaryAttribute>(1, syntax::Keyword);//TODO make precedence constants
	for(const string &s: syntax::Keywords) keywordAttribute->addKey(s);


	cpp->wordAttributes.push_back(std::move(keywordAttribute)); //TODO FREEZES

	// Correspond file extensions with respective syntax highlighters
	extHighlighters["cc"] = cpp.get();
	extHighlighters["h"] = cpp.get();

	// Add Syntax highlighters to buffer
	syntaxHighlighters.push_back(std::move(cpp));
}

void State::addFile(const std::string& file){
	util::FileReader reader;
	files.push_back(make_unique<File>(file, reader.readLines(file)));
	if (files.size()==1){
		activeFile = files[0].get();
	}

	// Set files syntax highlighter if it has one for its extension
	auto s = extHighlighters.find(files.back()->getFileExtension());
	if(s == extHighlighters.end()) files.back()->setSyntaxHighlighter(nullptr);
	else files.back()->setSyntaxHighlighter((*s).second);

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
	// std::unique_ptr<Action> action = activeMode->parseInput(move(input));
	// action->execute(*this);
}


File& State::getFile() {
	return *activeFile;
}

const File& State::getFile() const {
	return *activeFile;
}

void State::setActiveMode(Mode* nextMode){
	activeMode->onExit();
	activeMode = nextMode;
	nextMode->onEnter();
}

Mode& State::getMode(){
	return *activeMode;
}

const File& State::getMode() const {
	return *activeFile;
}


// Register functions -----------------
State::Register& State::getRegister() {
	return reg;
}

State::Register::Register(): paste{}, strSearch{}, charSearch{0},
 lastChangeAction{}, macroMap{}, scrollLength{0} {}


}
