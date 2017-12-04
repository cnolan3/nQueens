#include <iostream>

#include "model/nqueens.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2) { 
        cerr << "Invalid amount of command line arguments." << endl; 
        return 1;
    }

    const int size = atoi(argv[1]);
    Nqueens nqueens(size);
    
    while(nqueens.stat() == RUNNING) {
/*
        int* queens = nqueens.queens();
        for(int i = 0; i < size; i++) {
            cout << queens[i] << ", ";
        }
        cout << endl;
*/
        nqueens.step();
    }

    nqueens.print();

    if(nqueens.stat() == NO_SOLUTION)
        cout << "no solution" << endl;
    else if(nqueens.stat() == FINISHED)
        cout << "finished" << endl;

    return 0;
}
