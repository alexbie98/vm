#ifndef WORD_H
#define WORD_H

namespace utils{

	static const int tabSize = 4;

  const int TabSize = 4;

  static inline bool isWhitespace(char c){
    return c <= 32;
  }

  // Defines what it means for a word to be valid,
  // a word is made up of valid word characters as defined below.
  static bool isValidWordChar(char c){
    if(c <= 32) return false;
    if(c == '{' || c == '}' || c == '(' || c == ')' ||
       c == '[' || c == ']' || c == ';' || c == ':')
       return false;
    return true;
  }

  // Returns how many character slots c represents
  static size_t getCharWidth(char c)
  {
    if(c == '\t') return TabSize;
    return 1;
  }

}

#endif
