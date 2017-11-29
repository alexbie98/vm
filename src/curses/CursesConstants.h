#include <ncurses.h>

namespace curses{
  namespace attr{
    const int Normal = A_NORMAL;            //Normal display (no highlight)
    const int Standout = A_STANDOUT;        //Best highlighting mode of the terminal.
    const int Underline = A_UNDERLINE;      //Underlining
    const int Reverse= A_REVERSE;           //Reverse video
    const int Blink = A_BLINK;              //Blinking
    const int Dim = A_DIM;                  //Half bright
    const int Bold = A_BOLD;                //Extra bright or bold
    const int Protect = A_PROTECT;          //Protected mode
    const int Invis = A_INVIS;              //Invisible or blank mode
    const int AltCharSet = A_ALTCHARSET;    //Alternate character set
    const int CharText = A_CHARTEXT;        //Bit-mask to extract a character
  }

  namespace color{
    const int Black = COLOR_BLACK;
    const int Red = COLOR_RED;
    const int Green = COLOR_GREEN;
    const int Yellow = COLOR_YELLOW;
    const int Blue = COLOR_BLUE;
    const int Magenta = COLOR_MAGENTA;
    const int Cyan = COLOR_CYAN;
    const int White = COLOR_WHITE;
    const int Default = -1; 
  }
}
