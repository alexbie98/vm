#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller/Input.h"
#include <memory>

namespace vm {

class Controller {
	public:
		virtual std::unique_ptr<Input> getInput() = 0;
		virtual ~Controller() {}
};

}

#endif
