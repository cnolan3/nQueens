#ifndef __CURSESVIEW_H__
#define __CURSESVIEW_H__

#include <string>
#include <vector>

#include "../../util.h"

using std::string;

class Cursesview
{
public:
    std::vector<string> get_command();
    void update_view();
    void update_board(int* board, status modelStat);
    void init_board(int size);
    void unknown_command();
private:

};

#endif
