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
    virtual void update_view() = 0;
    virtual void update_board(int* board, status modelStat) = 0;
    virtual void init_board(int size) = 0;
    virtual void unknown_command() = 0;
private:

};

#endif
