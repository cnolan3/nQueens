/**
 * @file    board.h
 *
 * @brief   board object used to visualize the many queens board
 *
 * @author  Connor Nolan
**/

#ifndef __BOARD_H__
#define __BOARD_H__

class Board
{
public:
    Board(int width, int height);
    ~Board();

    enum piece {
        EMPTY,
        QUEEN
    };

    void reset();
    void setPiece(int x, int y, piece p);
    piece getPiece(int c, int y);
    
    int height();
    int width();

private:
    int m_width;
    int m_height;

    piece** m_board;
};

#endif
