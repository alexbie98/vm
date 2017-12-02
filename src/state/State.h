#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "data/Event.h"
#include "data/Subject.h"

namespace vm {

class File;
class Input;
class Mode;

class CommandMode;
class InsertMode;
class TerminalMode;

class Action;

class State: public Subject<State,Event>{
	
	public :
		struct Register {
			std::string paste;
			std::string strSearch;
			char charSearch;
			std::unique_ptr<Action> lastChangeAction;
			std::unordered_map<char, std::unique_ptr<Action>> macroMap;
			size_t scrollLength;
			private:
				Register();
			friend class State;
		};

	private:
		int runStatus;
		File* activeFile;
		Mode* activeMode;
		std::vector<std::unique_ptr<File>> files;

		std::unique_ptr<CommandMode> commandMode;
		std::unique_ptr<InsertMode> insertMode;
		std::unique_ptr<TerminalMode> terminalMode;
		
		Register reg;
		
		void executeAction();

	public:

		static const int RUNNING;
		static const int SAFE_EXIT;
		static const int ERROR_EXIT;

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
		
		Register& getRegister();
};

}


#endif
