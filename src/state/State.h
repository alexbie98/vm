#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include "state/SyntaxHighlighter.h"

#include "data/Event.h"
#include "data/Subject.h"

namespace vm {

class File;
class Input;
class Mode;

class CommandMode;
class InsertMode;
class ReplaceMode;
class TerminalMode;

class Action;

class State: public Subject<State,Event>{

	public :
		struct Register {
			std::string paste;
			std::string strSearch;
			char charSearch;
			std::unique_ptr<Action> lastChangeAction;
			std::unordered_map<int, std::unique_ptr<Action>> macroMap;
			std::unique_ptr<Action> currentMacro;
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
		std::unique_ptr<ReplaceMode> replaceMode;
		std::unique_ptr<TerminalMode> terminalMode;

		Register reg;
		bool buildingMacro;

		void executeAction();

		std::vector<std::unique_ptr<SyntaxHighlighter>> syntaxHighlighters;
		std::unordered_map<std::string, SyntaxHighlighter*> extHighlighters;
		void initExtHighlighters();

	public:
		// Prior to any function that triggers an event,
		// Must add observers.
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

		void setActiveMode(const std::type_info& nextMode);
		Mode& getMode();

		Register& getRegister();
		void startNewMacro();
		std::unique_ptr<Action> saveCurrentMacro();
		//TODO add tabsize constant?
};

}


#endif
