/**
 * @file    cursesview.cpp
 *
 * @brief   definition of cursesview object
 *
 * @author  Connor Nolan
**/

#include "cursesview.h"

#include <ncurses.h>
#include <string>
#include <sstream>

/**
 * get command from curses view
 *
 * @return    vector of arguments
**/
std::vector<string> Cursesview::get_command()
{
    std::vector<string> sv;

    std::string s = m_bwin->get_input();
    std::string tmp;

    std::istringstream iss(s);

    while(iss >> tmp)
        sv.push_back(tmp);

    return sv;
}

/**
 * update curses view
 *
 * @param    curCol, current column
 * @param    curStep, current step number
**/
void Cursesview::update_view(int curCol, int curStep)
{
    m_bwin->draw_board(curCol, curStep, m_modelStat);
}

/**
 * update board
 *
 * @param    board, array of queen positions
 * @param    modelStat, status of model algorithm
**/
void Cursesview::update_board(int* board, status modelStat)
{
    m_board->reset();

    for(int i = 0; i < m_board->width(); i++) {
        if(board[i] > -1)
            m_board->setPiece(i, board[i], Board::QUEEN);
    }

    m_modelStat = modelStat;
}

/**
 * initialize board
 *
 * @param    size, size of board
**/
void Cursesview::init_board(int size)
{
    if(m_board)
        delete m_board;

    m_board = new Board(size, size);

    m_bwin = new BWin(m_board);

    m_bwin->draw_board(-1, 0, m_modelStat);
}

/**
 * invalid command message
**/
void Cursesview::invalid_command()
{

}

/**
 * intro message
**/
void Cursesview::intro()
{

}

/**
 * help message
**/
void Cursesview::help()
{

}
