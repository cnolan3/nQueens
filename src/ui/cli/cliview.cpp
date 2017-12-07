/**
 * @file    cliview.cpp
 *
 * @brief   definition of cliview object
 *
 * @suthor  Connor Nolan
**/

#include <iostream>
#include <sstream>
#include <string>

#include "cliview.h"

using std::cout;
using std::endl;

/**
 * cliview constructor
**/
Cliview::Cliview()
{
    m_modelStat = RUNNING;
}

/**
 * get command from cin
 *
 * @param     args, vector of command arguments
 *
 * @return    command type
**/
command Cliview::get_command(std::vector<string> &args)
{
    cout << "> ";

    string s, tmp;

    getline(std::cin, s);
    std::istringstream iss(s);

    command ret = NO_COMMAND;

    if(iss >> tmp) {
        if(tmp == "quit" || tmp == "q")
            ret = QUIT;
        else if(tmp == "print" || tmp == "p")
            ret = PRINT;
        else if(tmp == "step" || tmp == "s")
            ret = STEP;
        else if(tmp == "set")
            ret = SET;
        else if(tmp == "run" || tmp == "r")
            ret = RUN;
        else if(tmp == "reset" || tmp == "rs")
            ret = RESET;
        else if(tmp == "speed")
            ret = SPEED;
        else if(tmp == "help" || tmp == "h")
            ret = HELP;
        else
            ret = INVALID_COMMAND;

        while(iss >> tmp) 
            args.push_back(tmp);    
    }

    return ret;
}

/**
 * update the view
 *
 * @param    curCol, current column
 * @param    curStep, current step number
**/
void Cliview::update_view(int curCol, int curStep)
{
    print_board(curCol, curStep); 
}

/**
 * update the board
 *
 * @param    board, array of queen positions on board
 * @param    modelStat, running status of algorithm
**/
void Cliview::update_board(int* board, status modelStat)
{
    m_board->reset();

    for(int i = 0; i < m_board->width(); i++) {
        if(board[i] > -1)
            m_board->setPiece(i, board[i], Board::QUEEN);
    }

    m_modelStat = modelStat;
}

/**
 * initialize the view board
 *
 * @param    size, size of board
**/
void Cliview::init_board(int size)
{
    if(m_board)
        delete m_board;

    m_board = new Board(size, size);
}

/**
 * invalid command message
**/
void Cliview::invalid_command()
{
    cout << "invalid command, use 'help' to list commands" << endl;
}

/**
 * intro message
**/
void Cliview::intro()
{
    cout << m_board->width() << "x" << m_board->height() << " board created" << endl;
    cout << endl;
    cout << "enter 'help' or 'h' for a list of commands" << endl;
}

/**
 * help message
**/
void Cliview::help()
{
    cout << "'quit', 'q'      quit program" << endl;
    cout << "'reset'          reset the current board" << endl;
    cout << "'set NUM'        creates new board of size NUM" << endl;
    cout << "'run', 'r'       run from current point, only prints result" << endl;
    cout << "'step', 's'      step into next iteration" << endl;
    cout << "'print', 'p'     print current board" << endl;
}

/**
 * print board to screen
 *
 * @param    curCol, current column
 * @param    curStep, current step number
**/
void Cliview::print_board(int curCol, int curStep)
{
    for(int i = 0; i < curCol; i++) {
        cout << "    ";
    }
    cout << "[C] " << endl;

    for(int i = 0; i < m_board->height(); i++) {
        for(int j = 0; j < m_board->width(); j++) {
            if(m_board->getPiece(j, i) == Board::EMPTY)
                cout << "[ ] ";
            else if(m_board->getPiece(j, i) == Board::QUEEN)
                cout << "[Q] ";
        }
        cout << endl;
    }

    cout << "step: " << curStep << endl;

    cout << "status: ";
    switch(m_modelStat) {
    case RUNNING:
        cout << "RUNNING" << endl;
        break;
    case NO_SOLUTION:
        cout << "NO SOLUTION" << endl;
        break;
    case FINISHED:
        cout << "FINISHED" << endl;
        break;
    default:
        break;
    }
}
