/**
 * @file    controller.h
 *
 * @brief   controller class to mediate between the nQueens model
 *          and the view.
 *
 * @author  Connor Nolan
**/

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class View;
class Nqueens;

class Controller
{
public:
    Controller(int argc, char* argv[]);
    ~Controller();

    void mainLoop();
private:
    bool running;
    View* m_view;
    Nqueens* m_model;
    int m_speed;
};

#endif
