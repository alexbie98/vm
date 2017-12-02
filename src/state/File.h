#ifndef FILE_H
#define FILE_H

#include "data/Pos.h"
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
  std::string name;
  std::vector<std::string> lines;
  Pos cursorPos;
  IndicatorPack indicatorPack;
  const SyntaxHighlighter *syntaxHighlighter;
  std::string fileExtension;

public:

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
  ConstWordIterator MakeWordIterator(Pos pos);
  ConstWordIterator wordBegin();
  ConstWordIterator wordEnd();

	const std::string& getName() const;
	const std::vector<std::string>& getLines() const;
  const IndicatorPack &getIndicatorPack() const;
  IndicatorPack &getIndicatorPack();
  const std::string &getFileExtension();


  void addString(std::string s, Pos pos);
  void addLines(std::vector<std::string> newLines, size_t lineNumber);
  void replaceString(std::string s, Pos pos);
  void replaceLines(std::vector<std::string> newLines, size_t lineNumber);
  void removeString(Pos start, Pos end);
  void removeLines(size_t start, size_t end);

  void undo();

  void parseAttributes();
  void setSyntaxHighlighter(const SyntaxHighlighter &s);
};

}

#endif
