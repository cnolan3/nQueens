/**
 * @file    controller.cpp
 *
 * @brief   definition of controller class
 *
 * @author  Connor Nolan
**/

#include "controller.h"
#include "../ui/view.h"
#include "../ui/cli/cliview.h"
#include "../ui/curses/cursesview.h"
#include "../model/nqueens.h"
#include "../util.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using std::cerr;
using std::endl;

/**
 * controller consructor
 *
 * @param    argc, number of command line args
 * @param    argv, command line args
**/
Controller::Controller(int argc, char* argv[])
{
    int initSize = 8;

// if making with curces ui
#ifdef CURSESUI               
    m_view = new Cursesview();

    if(argc > 1) {
        cerr << "usage:" << endl;
        cerr << "    " << argv[0] << endl;
        exit(1);
    }

    curses_init();

// if making with cli
#elif defined(CLI)
    m_view = new Cliview();

    if(argc > 2) {
        cerr << "usage:" << endl;
        cerr << "    " << argv[0] << "        (to start with default " << initSize << "x" << initSize << " board)" << endl;
        cerr << "or" << endl;
        cerr << "    " << argv[0] << " NUM    (to start with NUMxNUM board)" << endl;
        exit(1);
    }
    else if(argc == 2)
        initSize = atoi(argv[1]);
#endif

    m_view->init_board(initSize);

    m_model = new Nqueens(initSize);

    m_running = true;

    m_view->intro();

    m_speed = 10;
}

/**
 * controller destructor
 *
 * exits ncurses if compiled with it
**/
Controller::~Controller()
{
#ifdef CURSESUI
    curses_exit();
#endif
}

/**
 * main loop of program
 *
 * handles input from view and runs the model
**/
void Controller::mainLoop()
{
    std::vector<string> sv;
    command c;

    while(m_running) {

        c = m_view->get_command(sv);

        switch(c) {
        case QUIT:
            quit();
            break;
        case PRINT:
            print();
            break;
        case STEP:
            step();
            break;
        case SET:
            set(sv);
            break;
        case RUN:
            run();
            break;
        case RESET:
            reset();
            break;
        case SPEED:
            speed(sv);
            break;
        case HELP:
            help();
            break;
        case INVALID_COMMAND:
            invalid_command();
            break;
        case NO_COMMAND:
            break;
        default:
            break;
        }

        sv.clear();
    }
}

/**
 * quit command
**/
void Controller::quit()
{
    m_running = false;
}

/**
 * print command
**/
void Controller::print()
{
    m_view->update_view(m_model->curCol(), m_model->curStep());
}

/**
 * step command
**/
void Controller::step()
{
    m_model->step();
    m_view->update_board(m_model->queens(), m_model->stat());
    m_view->update_view(m_model->curCol(), m_model->curStep());
}

/**
 * set command
 *
 * @param    sv, vector of command arguments
**/
void Controller::set(std::vector<string> &sv)
{
    std::vector<string>::iterator it = sv.begin();

    if(it == sv.end()) 
        m_view->invalid_command();
    else {
        int size = atoi((*it).c_str());

        if(size < 1)
            m_view->invalid_command();
        else {

            delete m_model;
            m_model = new Nqueens(size);
            m_view->init_board(size);

            m_view->update_board(m_model->queens(), m_model->stat());
            m_view->update_view(m_model->curCol(), m_model->curStep());
        }
    }
}

/**
 * run command
**/
void Controller::run()
{
    while(m_model->stat() == RUNNING) {
        m_model->step(); 

    #ifdef CURSESUI
        m_view->update_board(m_model->queens(), m_model->stat());
        m_view->update_view(m_model->curCol(), m_model->curStep());
        usleep(1000 * m_speed);
    #endif
    }

    m_view->update_board(m_model->queens(), m_model->stat());
    m_view->update_view(m_model->curCol(), m_model->curStep());
}

/**
 * reset command
**/
void Controller::reset()
{
    int size = m_model->size();

    delete m_model;
    m_model = new Nqueens(size);
    m_view->init_board(size);
    m_view->update_board(m_model->queens(), m_model->stat());
    m_view->update_view(m_model->curCol(), m_model->curStep()); 
}

/**
 * speed command
 *
 * @param    sv, vector of command arguments
**/
void Controller::speed(std::vector<string> &sv)
{
    std::vector<string>::iterator it = sv.begin();

    if(it == sv.end())
        m_view->invalid_command();
    else {
        int speed = atoi((*it).c_str());

        if(speed < 0)
            m_view->invalid_command();
        else
            m_speed = speed; 
    }
}

/**
 * help command
**/
void Controller::help()
{
    m_view->help();
}

/**
 * invalid argument
**/
void Controller::invalid_command()
{
    m_view->invalid_command();
}
