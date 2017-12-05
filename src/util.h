#ifndef __UTIL_H__
#define __UTIL_H__

#include <ncurses.h>

enum status {
    RUNNING,
    NO_SOLUTION,
    FINISHED
};

void curses_init();
void curses_exit();

#endif
