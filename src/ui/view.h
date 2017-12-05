#ifndef __VIEW_H__
#define __VIEW_H__

#include <string>
#include <vector>

#include "../util.h"

using std::string;

class View
{
public:
    virtual std::vector<string> get_command() = 0;
    virtual void update_view(int curCol) = 0;
    virtual void update_board(int* board, status modelStat) = 0;
    virtual void init_board(int size) = 0;
    virtual void invalid_command() = 0;
    virtual void intro(int size) = 0;
    virtual void help() = 0;
private:

};

#endif
