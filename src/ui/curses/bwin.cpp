/**
 * @file    bwin.cpp
 *
 * @brief   definition of bwin object
 *
 * @author  Connor Nolan
**/

#include <ncurses.h>
#include <cstdio>
#include <panel.h>
#include <cstdlib>
#include <string>

#include "bwin.h"
#include "../board.h"

/**
 * bwin constructor
 *
 * @param    board, view board object
**/
BWin::BWin(Board* board)
    : m_board(board), m_origX(0), m_origY(0)
{
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);

    m_spaceH = 1;
    m_spaceW = 3;

    int h;
    int w;
    getmaxyx(stdscr, h, w);

    m_origX = (w / 2) - ((board->width() * m_spaceW) / 2);
    m_origY = (h / 2) - ((board->height() * m_spaceH) / 2);

    m_win = newwin(h - 4, w, 0, 0);
}

/**
 * bwin destructor
**/
BWin::~BWin()
{

}

/**
 * draw board on screen
 *
 * @param    curCol, current column
 * @param    curStep, current step number
 * @param    modelStat, model algorithm status
**/
void BWin::draw_board(int curCol, int curStep, status modelStat)
{
    clear();

    // space color pairs
    int* ca = new int(1);
    int* cb = new int(2);

    int* cpairnum = ca;

    // draw spaces in alternating colors
    for(int i = 0; i < m_board->width(); i++) {

        for(int j = 0; j < m_board->height(); j++) {

            // set colors for current column
            if(j == curCol) {
                *ca = 3;
                *cb = 4;
            }
            else {
                *ca = 1;
                *cb = 2;
            }
            
            // switch colors
            if(cpairnum == ca)
                cpairnum = cb;
            else if(cpairnum == cb)
                cpairnum = ca;

            char c;
            if(m_board->getPiece(j, i) == Board::QUEEN)
                c = 'Q';
            else
                c = ' ';

            draw_space(j, i, *cpairnum, c);
        }

        // switch colors again if board size is an even number
        if(m_board->width() % 2 == 0) {
            if(cpairnum == ca)
                cpairnum = cb;
            else if(cpairnum == cb)
                cpairnum = ca;
        }
    }

    // print step number and algorithm status
    mvprintw(m_origY + (m_spaceH * m_board->height()) + 1, m_origX, "step: %d", curStep);

    std::string stat;

    switch(modelStat) {
    case RUNNING:
        stat = "RUNNING";
        break;
    case NO_SOLUTION:
        stat = "NO SOLUTION";
        break;
    case FINISHED:
        stat = "FINISHED";
        break;
    default:
        break;
    }

    mvprintw(m_origY + (m_spaceH * m_board->height()) + 2, m_origX, "status: %s", stat.c_str());

    refresh();
}

/**
 * draw individual space of board
 *
 * @param    x, x coordinate on board
 * @param    y, y coordinate on board
 * @param    cpairnum, color pair number
 * @param    c, character to print on space
**/
void BWin::draw_space(int x, int y, int cpairnum, char c)
{
    attron(COLOR_PAIR(cpairnum));
    mvprintw(m_origY + (m_spaceH * y), m_origX + (m_spaceW * x) + 1, " %c ", c);
    attroff(COLOR_PAIR(cpairnum));
}

/**
 * get input from screen
 *
 * @return    input string
**/
std::string BWin::get_input()
{
    int h, w;
    getmaxyx(stdscr, h, w);

    attron(COLOR_PAIR(3));
    curs_set(1);

    // create command prompt bar
    for(int i = 0; i < w; i++) {
        mvprintw(h - 2, i, " ");
    }

    // print command prompt symbol
    mvprintw(h - 2, 3, "> ");
    move(h - 2, 5);

    refresh();

    // get user input string
    char s[256];
    getstr(s);

    attroff(COLOR_PAIR(3));
    curs_set(0);

    return std::string(s);
}
