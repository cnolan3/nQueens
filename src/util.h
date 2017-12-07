/**
 * @file    util.h
 *
 * @brief   utility functions for nQueens
 *
 * @author  Connor Nolan
**/

#ifndef __UTIL_H__
#define __UTIL_H__

#include <ncurses.h>

enum status {
    RUNNING,
    NO_SOLUTION,
    FINISHED
};

enum command {
    QUIT,
    PRINT,
    STEP,
    SET,
    RUN,
    RESET,
    SPEED,
    HELP,
    INVALID_COMMAND,
    NO_COMMAND
};

void curses_init();
void curses_exit();

#endif
