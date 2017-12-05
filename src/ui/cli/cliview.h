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

    std::vector<string> get_command();
    void update_view();
    void update_board(int* board, status modelStat);
    void init_board(int size);
    void unknown_command();
private:

    void print_board();

    Board* m_board; 

    status m_modelStat;
};

#endif
