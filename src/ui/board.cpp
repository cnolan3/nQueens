/**
 * @file    board.cpp
 *
 * @brief   definition of board object
 *
 * @author  Connor Nolan
**/

#include "board.h"

/**
 * board constructor
 *
 * @param    width, width of board to be created
 * @param    height, height of board to be created
**/
Board::Board(int width, int height)
    : m_width(width), m_height(height)
{
    m_board = new piece*[m_height];

    for(int i = 0; i < m_height; i++) {
        m_board[i] = new piece[m_width];
    }
}

/**
 * board destructor
**/
Board::~Board()
{

}

/**
 * reset board
 *
 * sets all spaces to empty
**/
void Board::reset()
{
    for(int i = 0; i < m_height; i++) {
        for(int j = 0; j < m_width; j++) {
            m_board[i][j] = EMPTY;  
        }
    }
}

/**
 * place a queen in a space
 *
 * @param    x, x coordinate
 * @param    y, y coordinate
 * @param    p, piece type
**/
void Board::setPiece(int x, int y, piece p)
{
    m_board[y][x] = p;
}

/**
 * get what piece is at a space
 *
 * @param    x, x coordinate
 * @param    y, y coordinate
 *
 * @return   piece type
**/
Board::piece Board::getPiece(int x, int y)
{
    return m_board[y][x];
}

/**
 * get height of board
 *
 * @return    board height
**/
int Board::height()
{
    return m_height;
}

/**
 * get width of board
 *
 * @return    width of board
**/
int Board::width()
{
    return m_width;
}
