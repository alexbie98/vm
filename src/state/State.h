#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include "data/Event.h"
#include "data/Subject.h"
#include <vector>
#include <map>
#include <memory>

namespace vm {

class File;
class Input;
class Mode;

class CommandMode;
class InsertMode;
class TerminalMode;

class State: public Subject<State,Event>{
		
	private:
		int runStatus;
		File* activeFile;
		Mode* activeMode;
		std::vector<std::unique_ptr<File>> files;

		std::unique_ptr<CommandMode> commandMode;
		std::unique_ptr<InsertMode> insertMode;
		std::unique_ptr<TerminalMode> terminalMode;
		
		void executeAction();

	public:
		static const int State::RUNNING;
		static const int State::SAFE_EXIT;
		static const int State::ERROR_EXIT;

		State();
		~State() override;

		void addFile(const std::string& file);
		void saveActiveFile();

		void setRunStatus(int runStatus);
		int getRunStatus() const;
		
		void handleInput(std::unique_ptr<Input> input);

		File& getFile();
		const File& getFile() const;
		
		void setActiveMode(Mode* nextMode);
		Mode& getMode();
		const File& getMode() const;



};

}


#endif
