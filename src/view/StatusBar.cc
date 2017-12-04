#include "view/StatusBar.h"
#include "state/State.h"
#include "state/File.h"
#include <iostream>
#include "util/Word.h"
#include "state/mode/Mode.h"
#include "state/mode/InsertMode.h"
#include "state/mode/ReplaceMode.h"
#include "state/mode/TerminalMode.h"
#include "state/mode/CommandMode.h"
#include "state/mode/TerminalModeInputParser.h"

namespace vm{

void StatusBar::drawLineNumber(const State &state, size_t windowWidth, size_t windowHeight){
  std::string lines;

  lines = std::to_string((state.getFile().getCursorPos().x == std::string::npos)? 0:state.getFile().getCursorPos().x) + ","
        + std::to_string((state.getFile().getCursorPos().y == std::string::npos)? 0:state.getFile().getCursorPos().y);
  win.drawString(lines, windowWidth - lines.size(), windowHeight - 1);
}

void StatusBar::draw(const State &state){
  widget->draw(state);

  Pos originalCursorPos = win.getCursorPos();
  const Mode* activeMode = state.getMode();
  size_t windowHeight = win.getHeight();
  size_t windowWidth = win.getWidth();

  //Clear the bottom line
  win.drawString(std::string(windowWidth,' '), 0, windowHeight - 1);

  if(dynamic_cast<const InsertMode*>(activeMode) != nullptr){


    std::string tag = "-- INSERT --";
    if(dynamic_cast<const ReplaceMode*>(activeMode) != nullptr) tag = "-- REPLACE --";

    win.drawString(tag, 0, windowHeight - 1);

    drawLineNumber(state, windowWidth, windowHeight);
  }
  else if(dynamic_cast<const TerminalMode*>(activeMode) != nullptr){
    std::string currentCommand = ":" + dynamic_cast<const TerminalMode*>(activeMode)->getTerminalParser()->getCommandBuffer();
    size_t commandHightWithWrap = currentCommand.size()/windowWidth + 1;
    //TODO is window width ever 0?

    //Clear bottoms lines to make space for command text
    for(int i = 0; i < commandHightWithWrap; i++)
      win.drawString(std::string(windowWidth,' '), 0, windowHeight - 1 - i);

    //Draw current buffered command
    for(int i = 0; i < commandHightWithWrap; i++){
      //TODO Doesnt take into account if wide characters are in command buffer text
      win.drawString(std::string(windowWidth,' '), 0, windowHeight - commandHightWithWrap + i); //wp
    }
  }
  else if(dynamic_cast<const CommandMode*>(activeMode) != nullptr){
    //do nothing for now lol
    drawLineNumber(state, windowWidth, windowHeight);
  }

  // Leave window cursor untouched
  win.setCursorPos(originalCursorPos);
}

}
