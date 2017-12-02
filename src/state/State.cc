#include "state/State.h"
#include "state/File.h"
#include "state/Mode.h"
#include "state/CommandMode.h"
#include "state/InsertMode.h"
#include "state/TerminalMode.h"
#include "controller/Input.h"
#include "util/FileReader.h"
#include "util/FileWriter.h"

using namespace std;

namespace vm {

const int State::RUNNING = 1;
const int State::SAFE_EXIT = 0;
const int State::ERROR_EXIT = 2;

State::State(): runStatus{RUNNING}, commandMode{new CommandMode()},
	insertMode{new InsertMode()}, terminalMode{new TerminalMode()} {}

State::~State(){}

void State::addFile(const std::string& file){
	util::FileReader reader;
	files.push_back(make_unique<File>(file, reader.readLines(file)));
	if (files.size()==1){
		activeFile = files[0].get();
	}
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



}
