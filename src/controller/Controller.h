#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller/Input.h"
namespace vm {

class Controller {
	
	public:
		virtual Input getInput() = 0;
};

}

#endif
