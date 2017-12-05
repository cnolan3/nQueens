#include "controller.h"
#include "../ui/view.h"
#include "../ui/cli/cliview.h"
#include "../ui/curses/cursesview.h"
#include "../model/nqueens.h"

Controller::Controller(int initSize)
{
#ifdef CURSESUI
    m_view = new Cursesview();
#elif defined(CLI)
    m_view = new Cliview();
#endif

    m_view->init_board(initSize);

    m_model = new Nqueens(initSize);

    running = true;

    m_view->intro(initSize);
}

Controller::~Controller()
{

}

void Controller::mainLoop()
{
    while(running) {
        std::vector<string> sv;
        std::vector<string>::iterator it;

        sv = m_view->get_command();

        it = sv.begin();

        if(*it == "quit" || *it == "q") 
            running = false;
        else if(*it == "print" || *it == "p")
            m_view->update_view(m_model->curCol());
        else if(*it == "step" || *it == "s") {
            int curCol = m_model->step();
            m_view->update_board(m_model->queens(), m_model->stat());
            m_view->update_view(curCol);
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
                }
            }
        }
        else if(*it == "reset" || *it == "r") {
            int size = m_model->size();

            delete m_model;
            m_model = new Nqueens(size);
            m_view->init_board(size);
        }
        else if(*it == "help" || *it == "h")
            m_view->help();
        else 
            m_view->invalid_command();
    }
}
