/**
 * @file    cursesview.h
 *
 * @brief   view for curses interface
 *
 * @author  Connor Nolan
**/

#ifndef __CURSESVIEW_H__
#define __CURSESVIEW_H__

#include <string>
#include <vector>

#include "../../util.h"
#include "../view.h"
#include "bwin.h"
#include "../board.h"

using std::string;

class Cursesview : public View
{
public:
    std::vector<string> get_command();
    void update_view(int curCol, int curStep);
    void update_board(int* board, status modelStat);
    void init_board(int size);
    void invalid_command();
    void intro(int size);
    void help();
private:

    BWin* m_bwin;

    Board* m_board;

    status m_modelStat;

};

#endif
