#include "view/FileText.h"
#include "state/State.h"
#include "state/File.h"
#include <iostream>
namespace vm{

//fix line wrapping to work with tabs
size_t FileText::drawLineWithWrap(const std::string &s, size_t y){
  size_t windowWidth = win.getWidth();
  size_t posInString = 0;

  while(posInString <= s.size()){
    win.drawString(s.substr(posInString, posInString+windowWidth), 0, y++);
    posInString+=windowWidth;
  }
}

void FileText::draw(const State &state){
  widget->draw(state);

  size_t drawLine = 0;
  for(auto it = state.getFile().MakeLineIterator(currentLine);
      it != state.getFile().lineEnd() && drawLine <= win.getHeight();
      ++it){
    if((*it).size() == 0) drawLine++;
    else drawLine+=drawLineWithWrap(*it, drawLine++);
  }
}

}
