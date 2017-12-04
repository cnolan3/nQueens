#ifndef __BWIN_H__
#define __BWIN_H__

#include <ncurses.h>

class Board;

class BWin
{
public:
    BWin();
    ~BWin();

    void redraw();
private:
    WINDOW* m_win; 
    Board* m_board;    
};

#endif