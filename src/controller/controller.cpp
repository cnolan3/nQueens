#include "controller.h"
#include "../ui/view.h"
#include "../ui/cli/cliview.h"
#include "../ui/curses/cursesview.h"
#include "../model/nqueens.h"

Controller::Controller()
{
#ifdef CURSESUI
    m_view = new Cursesview();
#elif defined(CLI)
    m_view = new Cliview();
#endif

    m_view->init_board(4);

    m_model = new Nqueens(4);

    running = true;
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

        if(*it == "quit") 
            running = false;
        else if(*it == "print")
            m_view->update_view();
        else if(*it == "step") {
            m_model->step();
            m_view->update_board(m_model->queens(), m_model->stat());
            m_view->update_view();
        }
        else 
            m_view->unknown_command();
    }
}
