#include "controller/CursesInput.h"
#include "controller/InputParser.h"
#include "action/Action.h"

using namespace std;

namespace vm {

CursesInput::CursesInput(char cursesIn): cursesIn{cursesIn} {}

CursesInput::~CursesInput() {}

std::unique_ptr<Action> CursesInput::beParsedBy(InputParser& parser) {
	return parser.parseInput(unique_ptr<CursesInput>(this));
}

char CursesInput::getCursesIn(){
	return cursesIn;
}

}

