#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include "data/Event.h"
#include "data/Subject.h"


namespace vm {

class Input;

class State: public Subject<State,Event> {

	public:
		State();
		~State() override;

		void addFile(const std::string& file);
		bool isValid();
		void handleInput(std::unique_ptr<Input> input);
};

}


#endif
