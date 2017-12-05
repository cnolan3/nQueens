#ifndef __BWIN_H__
#define __BWIN_H__

#include <ncurses.h>

#include "../../util.h"

class Board;

class BWin
{
public:
    BWin(Board* board);
    ~BWin();

    void draw_board(int curCol, int curStep, status modelStat);

    std::string get_input();
private:
    void draw_space(int x, int y, int cpairnum, char c);

    WINDOW* m_win; 
    Board* m_board;

    int m_origX;
    int m_origY;

    int m_spaceH;
    int m_spaceW;
};

#endif
