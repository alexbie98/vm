#ifndef FILE_H
#define FILE_H

#include <cstddef>
#include "data/Pos.h"
#include "data/Direction.h"
#include "state/LineIterator.h"
#include "state/CharIterator.h"
#include "state/WordIterator.h"
#include <string>
#include <vector>
#include <map>
#include <string>
#include "state/IndicatorPack.h"

namespace vm {

class SyntaxHighlighter;

class File{

	private:
		std::string name;
    //TODO if file is empty, add in one empty line.
		std::vector<std::string> lines; //Invariant: No line ever contains a newline
		Pos cursorPos;
		IndicatorPack indicatorPack;
		const SyntaxHighlighter *syntaxHighlighter;

	public:

		class BadOperationErr {};

		File(const std::string& name, std::vector<std::string> data);
		~File();

		// delete copy/move constructors & assignment
		File(const File& other) = delete;
		File(File&& other) = delete;
		File& operator=(const File& other) = delete;
		File& operator=(File&& other) = delete;

		// line iterator functions
		ConstLineIterator MakeLineIterator(size_t y) const;
		ConstLineIterator lineBegin() const;
		ConstLineIterator lineEnd() const;
		LineIterator MakeLineIterator(size_t y);
		LineIterator lineBegin();
		LineIterator lineEnd();

		// Char iterator functions
		ConstCharIterator MakeCharIterator(Pos pos) const;
		ConstCharIterator charBegin() const;
		ConstCharIterator charEnd() const;
		CharIterator MakeCharIterator(Pos pos);
		CharIterator charBegin();
		CharIterator charEnd();

		// Word iterator functions
		// If pos is not at start of word, MakeWordIterator
		// moves to next words beginning, or if there is no
		// next word, the end of the file.
		ConstWordIterator MakeWordIterator(Pos pos) const;
		ConstWordIterator wordBegin() const;
		ConstWordIterator wordEnd() const;

		// cursor and string getters
		const std::string& getName() const;
		std::string getFileExtension() const;
		const std::vector<std::string>& getLines() const;
		std::string getString(Pos start, Pos end) const;
		Pos getCursorPos() const;

		// cursor utility functions
		Pos toScreenCoords(Pos lineCoords) const;
		Pos toLineCoords(Pos screenCoords) const;
		bool isValidPos(Pos p) const;
		void setCursorPos(Pos p);
		void moveCursor(Direction d);

		void setName(std::string name);
		void addString(std::string s, Pos pos);
		void addLines(std::vector<std::string> newLines, size_t lineNumber);
		void replaceString(std::string s, Pos pos);
		void replaceLines(std::vector<std::string> newLines, size_t lineNumber);
		void removeString(Pos start, Pos end);
		void removeLines(size_t start, size_t end);

		// diffstack functions
		void undo();

		// syntax highlighting
		void parseAttributes();
		void setSyntaxHighlighter(const SyntaxHighlighter *s);
		const IndicatorPack& getIndicatorPack() const;
		IndicatorPack& getIndicatorPack();
};

}

#endif
