#include "state/Mode.h"
#include "controller/Input.h"
#include "controller/InputParser.h"

using namespace std;

namespace vm {

Mode::Mode(InputParser* parser): parser{parser} {}

Mode::~Mode() {}

unique_ptr<Action> Mode::parseInput(unique_ptr<Input> input){
	return input->beParsedBy(*parser);
}

}
