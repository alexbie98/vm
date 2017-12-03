#include "state/mode/Mode.h"
#include "controller/Input.h"
#include "controller/InputParser.h"

using namespace std;

namespace vm {

InputParser* Mode::getParser(){
	return parser.get();
}

Mode::Mode(unique_ptr<InputParser> parser,const string& name): 
	parser{move(parser)}, name{name} {}

Mode::~Mode() {}

unique_ptr<Action> Mode::parseInput(unique_ptr<Input> input){
	return input->beParsedBy(*parser);
}

string Mode::getName(){
	return name;
}


}
