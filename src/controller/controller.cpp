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

#ifdef CURSESUI
    m_view = new Cursesview();

    if(argc > 1) {
        cerr << "usage:" << endl;
        cerr << "    " << argv[0] << endl;
        exit(1);
    }

    curses_init();

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

    running = true;

    m_view->intro(initSize);
}

Controller::~Controller()
{

#ifdef CURSESUI
    curses_exit();
#endif
}

void Controller::mainLoop()
{
    std::vector<string> sv;
    std::vector<string>::iterator it;

    while(running) {

        sv = m_view->get_command();

        it = sv.begin();

        if(it != sv.end()) {
            if(*it == "quit" || *it == "q") 
                running = false;
            else if(*it == "print" || *it == "p")
                m_view->update_view(m_model->curCol(), m_model->curStep());
            else if(*it == "step" || *it == "s") {
                m_model->step();
                m_view->update_board(m_model->queens(), m_model->stat());
                m_view->update_view(m_model->curCol(), m_model->curStep());
            }
            else if(*it == "set") {
                it++;
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
            else if(*it == "run" || *it == "r") {
                while(m_model->stat() == RUNNING) {
                    m_model->step(); 

                #ifdef CURSESUI
                    m_view->update_board(m_model->queens(), m_model->stat());
                    m_view->update_view(m_model->curCol(), m_model->curStep());
                    usleep(100000);
                #endif
                }

                m_view->update_board(m_model->queens(), m_model->stat());
                m_view->update_view(m_model->curCol(), m_model->curStep());
            }
            else if(*it == "reset") {
                int size = m_model->size();

                delete m_model;
                m_model = new Nqueens(size);
                m_view->init_board(size);
                m_view->update_board(m_model->queens(), m_model->stat());
                m_view->update_view(m_model->curCol(), m_model->curStep()); 
            }
            else if(*it == "help" || *it == "h")
                m_view->help();
            else 
                m_view->invalid_command();
        }
    }
}
