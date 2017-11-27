#ifndef FILE_H
#define FILE_H

#include "data/Pos.h"
#include "state/LineIterator.h"
#include <string>
#include <vector>

namespace vm {

class File{
  std::string name;
  std::vector<std::string> lines;
  Pos cursorPos;

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

	
	const std::string& getName() const;
	const std::vector<std::string>& getLines() const;


  void addString(std::string s, Pos pos);
  void addLines(std::vector<std::string> newLines, size_t lineNumber);
  void replaceString(std::string s, Pos pos);
  void replaceLines(std::vector<std::string> newLines, size_t lineNumber);
  void removeString(Pos start, Pos end);
  void removeLines(size_t start, size_t end);

  void undo();
};

}

#endif
