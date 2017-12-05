#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class View;
class Nqueens;

class Controller
{
public:
    Controller();
    ~Controller();

    void mainLoop();
private:
    bool running;
    View* m_view;
    Nqueens* m_model;
};

#endif
