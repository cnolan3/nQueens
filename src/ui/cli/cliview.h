/**
 * @file    cliview.h
 *
 * @brief   view object for the command line interface
 *
 * @author  Connor Nolan
**/

#ifndef __CLIVIEW_H__
#define __CLIVIEW_H__

#include "../view.h"
#include "../board.h"
#include "../../util.h"

#include <vector>

class Cliview : public View
{
public:
    Cliview();

    command get_command(std::vector<string> &args);
    void update_view(int curCol, int curStep);
    void update_board(int* board, status modelStat);
    void init_board(int size);
    void invalid_command();
    void intro();
    void help();
private:

    void print_board(int curCol, int curStep);

    Board* m_board; 

    status m_modelStat;
};

#endif
