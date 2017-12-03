#include "controller/KeyInput.h"
#include "controller/InputParser.h"
#include "action/Action.h"

using namespace std;

namespace vm {

KeyInput::KeyInput(int key): key{key} {}

KeyInput::~KeyInput() {}

std::unique_ptr<Action> KeyInput::beParsedBy(InputParser& parser) {
	return parser.parseInput(unique_ptr<KeyInput>(this));
}

int KeyInput::getKey(){
	return key;
}

}

