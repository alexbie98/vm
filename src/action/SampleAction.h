#ifndef SAMPLE_ACTION_H
#define SAMPLE_ACTION_H

#include "action/Action.h"

namespace vm {

class SampleAction : public Action {

	private:
		void doAction(State& context) override;

	public:
		SampleAction(size_t multi = 1, std::unique_ptr<Action> nextAction
				= std::unique_ptr<Action>{});
		~SampleAction() override;

};

}



#endif
