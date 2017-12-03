#include "action/SampleAction.h"
#include "state/State.h"
#include "state/File.h"

using namespace std;
namespace vm {

void SampleAction::doAction(State& context) {


}

SampleAction::SampleAction(size_t multi, unique_ptr<Action> nextAction):
	Action{multi,move(nextAction)} {}

unique_ptr<Action> SampleAction::clone() {
	unique_ptr<Action> nextClone;
	if (nextClone) nextClone = nextAction->clone();
	return make_unique<SampleAction>(multi,move(nextClone));
}

SampleAction::~SampleAction() {}

}

