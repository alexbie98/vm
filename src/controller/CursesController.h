#ifndef CURSES_CONTROLLER_H
#define CURSES_CONTROLLER_H

#include "controller/Controller.h"
#include "curses/CursesInstance.h"

namespace vm {

class CursesController : public Controller {

	private:
		curses::CursesInstance& cInst;
	public:
		CursesController(curses::CursesInstance& cInst);
		std::unique_ptr<Input> getInput() override;
		~CursesController() override;
};

}

#endif
