#include <cstdlib>
#include <iostream>
#include <cstdio>

#include "nqueens.h"

using std::cout;
using std::cerr;
using std::endl;

/**
 * Nqueens constructor
 *
 * @param    size, number of spaces along each side of the board
**/
Nqueens::Nqueens(int size)
    : m_curCol(0), m_size(size), m_status(RUNNING)
{
    m_queens = new int[m_size];

    for(int i = 0; i < m_size; i++) {
        m_queens[i] = -1;
    }

    m_board = new space*[m_size];

    for(int i = 0; i < m_size; i++) {
        m_board[i] = new space[m_size];

        for(int j = 0; j < m_size; j++) {
            m_board[i][j] = EMPTY;
        }
    }

    m_last = 0;
    m_curStep = 0;
}

/**
 * Nqueens destructor
**/
Nqueens::~Nqueens()
{

}

/**
 * size
 *
 * @return    size in spaces of each side of the board
**/
int Nqueens::size()
{
    return m_size;
}

/**
 * get current column
 *
 * @return    current column
**/
int Nqueens::curCol()
{
    return m_curCol;
}

/**
 * get current step number
 *
 * @return    current step
**/
int Nqueens::curStep()
{
    return m_curStep;
}

/**
 * take next step in algorithm
 *
 * @return    index of current column
**/
void Nqueens::step()
{
    if(m_status != RUNNING)
        return;

    int i = m_last;
    while(i < m_size) {
        if(m_board[m_curCol][i] == EMPTY) {
            place(m_curCol, i);
            break;
        }

        i++;
    }

    // if queen could not have been placed, go back a column
    if(i >= m_size) {
        m_curCol--;
        
        m_last = m_queens[m_curCol] + 1;

        remove(m_curCol);

        if(m_curCol < 0) {
            m_status = NO_SOLUTION;
        }
    }
    else {
        m_curCol++;   

        m_last = 0;

        if(m_curCol >= m_size) {
            m_status = FINISHED;
        }
    }

    m_curStep++;
}

/**
 * print contents of board for debugging
**/
void Nqueens::print()
{
    cout << "step, col: " << m_curCol << endl;
    for(int i = 0; i < m_size; i++) {
        for(int j = 0; j < m_size; j++) {
            if(i == m_queens[j])
                cout << "Q, ";
            else if(m_board[j][i] == EMPTY)
                cout << "E, ";
            else if(m_board[j][i] == ATTACKED)
                cout << "A, ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * postions of queens on board
 *
 * returns an array of integers representing the space in each column that a queen
 * is in, 0 being the top space. -1 represents a column without a queen.
 *
 * @return    array of positions
**/
int* Nqueens::queens()
{
    return m_queens;    
}

/**
 * get algorithm status
 *
 * @return    algorithm status
**/
status Nqueens::stat()
{
    return m_status;
}

/**
 * place a queen on the board
 *
 * places a queen and sets space status
 *
 * @param    x, x coordinate to place
 * @param    y, y coordinate to place
**/
void Nqueens::place(int x, int y)
{
    if(x >= m_size || x < 0)
        cerr << "Nqueens place error: x out of bounds" << endl;

    if(y >= m_size || y < 0)
        cerr << "Nqueens place error: y out of bounds" << endl;

    m_queens[x] = y;

    for(int i = 0; i < m_size; i++) {
        for(int j = 0; j < m_size; j++) {
            if(i == x || j == y || (x - i) == (y - j) || (x - i) == (j - y) || i == j)
                m_board[i][j] = ATTACKED;
        }
    }
}

/**
 * remove queen from column
 *
 * remove queen and update space status
 *
 * @param    col, column to remove from
**/
void Nqueens::remove(int col)
{
    if(col >= m_size || col < 0) {
        return;
    }

    if(m_queens[col] < 0)
        return;

    // remove queen from list
    m_queens[col] = -1;

    // reset board
    for(int i = 0; i < m_size; i++) {
        for(int j = 0; j < m_size; j++) {
            m_board[i][j] = EMPTY;
        }
    }

    // replace all other queens
    for(int i = 0; i < m_size; i++) {
        if(m_queens[i] > -1) {
            place(i, m_queens[i]);
        }
    }
}
