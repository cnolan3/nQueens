/**
 * @file    util.cpp
 *
 * @brief   definition of utility functions
 *
 * @author  Connor Nolan
**/

#include "util.h"

/**
 * initialize ncurses settings
**/
void curses_init()
{
    initscr();
    cbreak();

    start_color();
    use_default_colors();

    curs_set(0);
}

/**
 * exit ncurses
**/
void curses_exit()
{
    endwin();
}
