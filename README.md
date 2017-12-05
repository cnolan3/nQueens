# nQueens

Program that solves a many-queens board of any size using bactracking.

## how to run

install ncurses to compile
```
$ sudo apt-get install libncurses5-dev libncursesw5-dev
```

make with CLI
```
$ make
```
or
```
$ make UI=cli
```
make with ncurses ui
```
$ make UI=curses
```
## commands

### CLI
```
'help', 'h'        list commands
'quit', 'q'        quit program\n
'reset'            reset board
'set NUM'          create new NUMxNUM board
'run', 'r'         run from current point until a solution is found
'step', 's'        move forward one step
'print', 'p'       print current board
 ```
 ### CURSES
 ```
 'quit', 'q'       quit program
 'reset'           reset board
 'set NUM'         create new NUMxNUM board
 'run', 'r'        run from current point until a solution is found
 'step', 's'       move forward on step
 ```
