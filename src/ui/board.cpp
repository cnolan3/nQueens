/**
 * @file    board.cpp
 *
 * @brief   definition of board object
 *
 * @author  Connor Nolan
**/

#include "board.h"

Board::Board(int width, int height)
    : m_width(width), m_height(height)
{
    m_board = new piece*[m_height];

    for(int i = 0; i < m_height; i++) {
        m_board[i] = new piece[m_width];
    }
}

Board::~Board()
{

}

void Board::reset()
{
    for(int i = 0; i < m_height; i++) {
        for(int j = 0; j < m_width; j++) {
            m_board[i][j] = EMPTY;  
        }
    }
}

void Board::setPiece(int x, int y, piece p)
{
    m_board[y][x] = p;
}

Board::piece Board::getPiece(int x, int y)
{
    return m_board[y][x];
}

int Board::height()
{
    return m_height;
}

int Board::width()
{
    return m_width;
}
