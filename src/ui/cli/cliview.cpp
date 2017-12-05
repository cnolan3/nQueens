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

void Cliview::update_view()
{
    print_board(); 
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
    m_board = new Board(size, size);
}

void Cliview::unknown_command()
{
    cout << "unknown command" << endl;
}

void Cliview::print_board()
{
    for(int i = 0; i < m_board->height(); i++) {
        for(int j = 0; j < m_board->width(); j++) {
            if(m_board->getPiece(j, i) == Board::EMPTY)
                cout << "[X] ";
            else if(m_board->getPiece(j, i) == Board::QUEEN)
                cout << "[Q] ";
        }
        cout << endl;
    }

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
