#ifndef EDITOR_H
#define EDITOR_H

#include "curses/CursesInstance.h"
#include "state/State.h"
#include "view/CursesView.h"
#include "controller/CursesController.h"
#include <string>
#include <vector>
#include <utility>

namespace vm {
class Editor {
	private:
		std::unique_ptr<State> state;
		std::unique_ptr<Controller> controller;
		std::unique_ptr<View> view;
		curses::CursesInstance cursesInstance;

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
