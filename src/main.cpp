#include <iostream>

#include "controller/controller.h"

using namespace std;

int main(int argc, char *argv[])
{
    Controller c(argc, argv);

    c.mainLoop();

    return 0;
}
