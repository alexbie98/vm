#include "action/SampleAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void SampleAction::doAction(State& context) {


}

SampleAction::SampleAction(size_t multi, std::unique_ptr<Action> nextAction):
	Action{multi,move(nextAction)} {}

SampleAction::~SampleAction() {}

}

