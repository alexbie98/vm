#ifndef WORD_H
#define WORD_H

namespace utils{

  inline bool isWhitespace(char c){
    return c <= 32;
  }

  // Defines what it means for a word to be valid,
  // a word is made up of valid word characters as defined below.
  bool isValidWordChar(char c){
    if(c <= 32) return false;
    if(c == '{' || c == '}' || c == '(' || c == ')' ||
       c == '[' || c == ']' || c == ';' || c == ':')
       return false;
    return true;
  }

  // Returns how many character slots c represents
  int getCharWidth(char c)
  {
    if(c == '\t') return 8;
    return 1;
  }

}

#endif
