#include "view/FileText.h"
#include "state/State.h"
#include "state/File.h"

namespace vm{

void FileText::draw(const State &state){
  widget->draw(state);

  size_t drawLine = 0;
  for(auto it = state.getFile().MakeLineIterator(currentLine); it != state.getFile().lineEnd(); ++it){
      size_t lineSize = (*it).size();
      while(lineSize > 0){
        win.drawString(*it, drawLine, 0); // substr it?
        lineSize-=win.getWidth();
        drawLine++;
      }
  }
}

}
