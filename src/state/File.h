#ifndef FILE_H
#define FILE_H

#include "data/Pos.h"
#include <string>
#include <vector>

namespace vm {

class File{
  bool isEditable;
  std::string name;
  std::vector<std::string> data;
  Pos cursorPos;

public:

  class const_line_iterator //Move outside?
  {
    const std::vector<std::string>& data;
    int lineNumber;

    const_line_iterator(const std::vector<std::string>& data, int lineNumber):
      data{data}, lineNumber{lineNumber}{}
  public:
    bool operator!=(const const_line_iterator &other)const{return lineNumber != other.lineNumber;}
    const std::string &operator*() const{return data[lineNumber];}
    const const_line_iterator &operator++()
    {
      lineNumber++;
      return *this;
    }
    friend class File;
  };

  const_line_iterator makeIterator(int y){return const_line_iterator(data, y);}
  const_line_iterator begin()const{return const_line_iterator(data, 0);}
  const_line_iterator end()const{const_line_iterator(data, data.size());}

  // delete copy/move constructors & assignment
  File(const File& other) = delete;
  File(File&& other) = delete;
  File& operator=(const File& other) = delete;
  File& operator=(File&& other) = delete;

  void addString(std::string s, Pos pos);
  void addLines(std::vector<std::string> lines, size_t lineNumber);
  void replaceString(std::string s, Pos pos);
  void replaceLines(std::vector<std::string> lines, size_t lineNumber);
  void removeString(Pos start, Pos end);
  void removeLines(size_t start, size_t end);
  void undo();
};

}

#endif
