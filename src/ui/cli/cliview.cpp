#include <iostream>
#include <sstream>
#include <string>

#include "cliview.h"

using std::cout;
using std::endl;

Cliview::Cliview()
{
    m_modelStat = RUNNING;
}

std::vector<string> Cliview::get_command()
{
    cout << "> ";

    string s, tmp;
    std::vector<string> sv;

    getline(std::cin, s);
    std::istringstream iss(s);

    while(iss >> tmp) {
        sv.push_back(tmp);    
    }

    return sv;
}

void Cliview::update_view(int curCol, int curStep)
{
    print_board(curCol, curStep); 
}

void Cliview::update_board(int* board, status modelStat)
{
    m_board->reset();

    for(int i = 0; i < m_board->width(); i++) {
        if(board[i] > -1)
            m_board->setPiece(i, board[i], Board::QUEEN);
    }

    m_modelStat = modelStat;
}

void Cliview::init_board(int size)
{
    if(m_board)
        delete m_board;

    m_board = new Board(size, size);
}

void Cliview::invalid_command()
{
    cout << "invalid command, use 'help' to list commands" << endl;
}

void Cliview::intro(int size)
{
    cout << size << "x" << size << " board created" << endl;
    cout << endl;
    cout << "enter 'help' or 'h' for a list of commands" << endl;
}

void Cliview::help()
{
    cout << "'quit', 'q'      quit program" << endl;
    cout << "'reset'          reset the current board" << endl;
    cout << "'set NUM'        creates new board of size NUM" << endl;
    cout << "'run', 'r'       run from current point, only prints result" << endl;
    cout << "'step', 's'      step into next iteration" << endl;
    cout << "'print', 'p'     print current board" << endl;
}

void Cliview::print_board(int curCol, int curStep)
{
    for(int i = 0; i < curCol; i++) {
        cout << "    ";
    }
    cout << "[C] " << endl;

    for(int i = 0; i < m_board->height(); i++) {
        for(int j = 0; j < m_board->width(); j++) {
            if(m_board->getPiece(j, i) == Board::EMPTY)
                cout << "[X] ";
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
