#include <iostream>

#include "controller/controller.h"

using namespace std;

int main(int argc, char *argv[])
{
    int initSize = 8;

    if(argc > 2 || argc < 1) {
        cout << "usage:" << endl;
        cout << "    " << argv[0] << "        (to start with default " << initSize << "x" << initSize << " board)" << endl;
        cout << "or" << endl;
        cout << "    " << argv[0] << " NUM    (to start with NUMxNUM board)" << endl;
        exit(1);
    }
    else if(argc == 2)
        initSize = atoi(argv[1]);

    Controller c(initSize);

    c.mainLoop();

    return 0;
}
