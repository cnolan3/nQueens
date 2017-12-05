#ifndef __NQUEENS_H__
#define __NQUEENS_H__

#include "../util.h"

class Nqueens
{
public:
    Nqueens(int size);
    ~Nqueens();

    int size();
    int curCol();
    int curStep();

    void step();               // take next step in simulation
    void print();

    int* queens();             // return positions of queens    

    status stat();

private:

    enum space {
        EMPTY,
        ATTACKED
    };

    int m_curCol;              // column currrently being set

    int m_size;                // number of spaces along each side

    int m_last;                // row number of previous iteration

    int m_curStep;             // current step number

    status m_status;           // algorithm status

    int* m_queens;             // where on each column a queen is placed
                               // -1 for not placed

    space** m_board;           // 2d array of board, shows wich spaces are
                               // being attacked and which are not

    void place(int x, int y);
    void remove(int col);

};

#endif
