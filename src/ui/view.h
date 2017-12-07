/**
 * @file    view.h
 *
 * @brief   view pure virtual adapter object. can point ro a CLI view or a
 *          curese view.
 *
 * @author  Connor Nolan
**/

#ifndef __VIEW_H__
#define __VIEW_H__

#include <string>
#include <vector>

#include "../util.h"
#include "../model/nqueens.h"

using std::string;

class View
{
public:
    virtual command get_command(std::vector<string> & args) = 0;
    virtual void update_view(int curCol, int curStep) = 0;
    virtual void update_board(int* board, status modelStat) = 0;
    virtual void init_board(int size) = 0;
    virtual void invalid_command() = 0;
    virtual void intro() = 0;
    virtual void help() = 0;
private:

};

#endif
