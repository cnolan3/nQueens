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

BWin::~BWin()
{

}

void BWin::draw_board(int curCol, int curStep, status modelStat)
{
    clear();

    int* ca = new int(1);
    int* cb = new int(2);

    int* cpairnum = ca;

    for(int i = 0; i < m_board->width(); i++) {

        for(int j = 0; j < m_board->height(); j++) {

            if(j == curCol) {
                *ca = 3;
                *cb = 4;
            }
            else {
                *ca = 1;
                *cb = 2;
            }
            
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

        if(m_board->width() % 2 == 0) {
            if(cpairnum == ca)
                cpairnum = cb;
            else if(cpairnum == cb)
                cpairnum = ca;
        }
    }

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

void BWin::draw_space(int x, int y, int cpairnum, char c)
{
    attron(COLOR_PAIR(cpairnum));
    mvprintw(m_origY + (m_spaceH * y), m_origX + (m_spaceW * x) + 1, " %c ", c);
    attroff(COLOR_PAIR(cpairnum));
}

std::string BWin::get_input()
{
    int h, w;
    getmaxyx(stdscr, h, w);

    attron(COLOR_PAIR(3));
    for(int i = 0; i < w; i++) {
        mvprintw(h - 2, i, " ");
    }

    mvprintw(h - 2, 3, "> ");
    move(h - 2, 5);

    refresh();

    char s[256];
    getstr(s);

    attroff(COLOR_PAIR(3));

    return std::string(s);
}
