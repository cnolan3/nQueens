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

#include <vector>
#include <string>

using std::string;

class View;
class Nqueens;

class Controller
{
public:
    Controller(int argc, char* argv[]);
    ~Controller();

    void mainLoop();
private:
    // commands
    void quit();
    void print();
    void step();
    void set(std::vector<string> &sv);
    void run();
    void reset();
    void speed(std::vector<string> &sv);
    void help();
    void invalid_command();

    bool m_running;       // mainloop status
    View* m_view;         // view
    Nqueens* m_model;     // nqueens model
    int m_speed;          // speed of 'run' command
};

#endif
