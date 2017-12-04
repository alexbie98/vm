#include "view/FileText.h"
#include "state/State.h"
#include "state/File.h"
#include <iostream>
#include <map>
#include "util/Word.h"

namespace vm{

//fix line wrapping to work with tabs
size_t FileText::drawLineWithWrap(const std::string &s, size_t y, const State &state){
  size_t windowWidth = win.getWidth();
  size_t linesAdded = 1;
  size_t widthAdded = 0;
  size_t x = 0;

  Pos fileCursorPos((state.getFile().getCursorPos().x == std::string::npos)? 0:state.getFile().getCursorPos().x,
                    (state.getFile().getCursorPos().y == std::string::npos)? 0:state.getFile().getCursorPos().y);

  for(char c: s){
    if(widthAdded + utils::getCharWidth(c) > windowWidth){
      y++;
      widthAdded = 0;
      linesAdded++;
    }
    win.drawString(std::string(1, c), widthAdded, y);
    widthAdded+=utils::getCharWidth(c);
    if(currentLine + y == fileCursorPos.y && x == fileCursorPos.x) screenCursorPos = Pos(x,y);
    x++;
  }
  return linesAdded;
}

// it should be at the first range indicator for its line
size_t FileText::drawLineWithWrap(const std::string &s, size_t y, std::vector<std::pair<Pos, int> >::const_iterator &it, int &insideRange){
  size_t windowWidth = win.getWidth();

  auto temp = syntaxColorMap.find(it->second);
  if(insideRange != -1 && temp != syntaxColorMap.end())
    win.setDrawColor(temp->second);
      //TODO syntax nubmers must be >=0

  for(int i = 0; i < s.size(); i++){ //TODO fix tabs?
    if(insideRange != -1) win.drawString(std::string(s[i], 1), i%windowWidth, y + i/windowWidth);
    if(i == it->first.x){
      ++it;
      if(insideRange != -1) insideRange = -1;
      else insideRange = it->second;


      auto temp = syntaxColorMap.find(it->second);
      if(insideRange != -1 && temp != syntaxColorMap.end())
        win.setDrawColor(temp->second);
    }
  }

  return y + s.size() % windowWidth;
}//not inside, be negative, otherwise inside range is

//set color beforehand
size_t FileText::drawLineWithWrap(const std::string &s, size_t y, std::vector<std::pair<Pos, size_t> >::const_iterator &it){
  size_t windowWidth = win.getWidth();
  size_t wordSize = it->second;

  for(int i = 0; i < s.size(); i++){
    if(i = it->first.x){
      for(int j = 0; j != it->second; j++) win.drawString(std::string(s[i], 1), i%windowWidth, y + i/windowWidth);
      ++it;
    }
  }//TODO CHECK

  return y + s.size() % windowWidth;
}

void FileText::draw(const State &state){
  widget->draw(state);

  //Change currentLine if file cursor is outside window;
  if(state.getFile().getCursorPos().y > currentLine + win.getHeight()){
    currentLine += state.getFile().getCursorPos().y - win.getHeight();
  }
  if(state.getFile().getCursorPos().y < currentLine){
    //Subtract difference
    currentLine += state.getFile().getCursorPos().y - currentLine;
  }


  //Draw all text in default colors first.
  size_t drawLine = 0;
  for(auto it = state.getFile().MakeLineIterator(currentLine);
      it != state.getFile().lineEnd() && drawLine <= win.getHeight();
      ++it){
    if((*it).size() == 0) drawLine++;
    else drawLine+=drawLineWithWrap(*it, drawLine,state);
  }

  win.setDrawColor(5);
  while(drawLine <= win.getHeight()) win.drawString(std::string(1, '~'), 0, drawLine++);
  win.setDrawColor(1);

  win.setCursorPos(screenCursorPos);

  /*
  //Draw word highlights over default based on precedence
  //TODO ensure that colors are in precendence order

  for(auto it = state.getFile().getIndicatorPack().wordIndicators.begin();
      it != state.getFile().getIndicatorPack().wordIndicators.end();
      ++it){

        // for(auto jt = it->words.begin(); jt !=it->words.end(); jt++)
        //   std::cout << "(" << jt->first.x << "," << jt->first.y << ")" << std::endl;

    drawLine = 0;

    //set iterator to find first word that is on line
    std::vector<std::pair<Pos, size_t>>::const_iterator word = it->words.begin();
    for(;
        word != it->words.end() && word->first.y < currentLine;
        ++word);

    //set appropriate draw color for syntax
    auto temp = syntaxColorMap.find(word->second);
    if(temp != syntaxColorMap.end())
      win.setDrawColor(temp->second);


    for(auto it = state.getFile().MakeLineIterator(currentLine);
        it != state.getFile().lineEnd() && drawLine <= win.getHeight();
        ++it){
      if((*it).size() == 0) drawLine++;
      else drawLine+=drawLineWithWrap(*it, drawLine++, word);
    }
  }

  //Draw range highlights on top

  //First range at or after currentLine
  auto currentRange = state.getFile().getIndicatorPack().rangeIndicators.begin();
  for(;
      currentRange != state.getFile().getIndicatorPack().rangeIndicators.end() && currentRange->first.y < currentLine;
      ++currentRange);

  drawLine = 0;
  int insideRange = -1;

  for(auto it = state.getFile().MakeLineIterator(currentLine);
      it != state.getFile().lineEnd() && drawLine <= win.getHeight();
      ++it){
    if((*it).size() == 0) drawLine++;
    else drawLine+=drawLineWithWrap(*it, drawLine++, currentRange, insideRange);
  } //*/

}

}
