#ifndef TERMINAL_MODE_H
#define TERMINAL_MODE_H

#include "state/mode/Mode.h"

namespace vm {

class TerminalModeInputParser;

class TerminalMode : public Mode {

	public:
		TerminalMode();
		~TerminalMode();

		void onEnter() override;
		void onExit() override;
		void reset() override;

		TerminalModeInputParser* getTerminalParser();
		const TerminalModeInputParser* getTerminalParser()const;

};

}

#endif
