#ifndef EDITOR_H
#define EDITOR_H

#include "curses/CursesInstance.h"
#include "state/State.h"
#include "view/CursesView.h"
#include "controller/CursesController.h"
#include <string>
#include <vector>
#include <memory>

namespace vm {
class Editor {
	private:
		curses::CursesInstance cursesInstance;
		std::unique_ptr<State> state;
		std::unique_ptr<View> view;
		std::unique_ptr<Controller> controller;

	public:
		Editor(const std::vector<std::string>& args);

		// delete copy/move constructors & assignment
		Editor(const Editor& other) = delete;
		Editor(Editor&& other) = delete;
		Editor& operator=(const Editor& other) = delete;
		Editor& operator=(Editor&& other) = delete;

		int run();
};



}

#endif
