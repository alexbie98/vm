#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include "data/Event.h"
#include "data/Subject.h"
#include "File.h"
#include <vector>

namespace vm {

class Input;

class State: public Subject<State,Event>{
		File *activeFile;
	public:
		State();
		~State() override;

		void addFile(const std::string& file);
		bool isValid();
		void handleInput(std::unique_ptr<Input> input);

		File& getFile(){return *activeFile;}
		const File& getFile()const{return *activeFile;}
};

}


#endif
