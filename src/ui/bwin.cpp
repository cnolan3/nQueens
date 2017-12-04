#include <ncurses.h>
#include <cstdio>
#include <panel.h>
#include <cstdlib>

#include "bwin.h"
#include "board.h"

BWin::BWin()
{
    initscr();
    cbreak();
    noecho();

    start_color();
    use_default_colors();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_BLUE, COLOR_WHITE);

    int h;
    int w;
    getmaxyx(stdscr, h, w);

    m_win = newwin(h, w, 0, 0);
}

BWin::~BWin()
{

}
