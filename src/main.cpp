#include"nqueens.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2) { 
        cerr << "Invalid amount of command line arguments." << endl; 
        return 1;
    }

    const int size = atoi(argv[1]);
    Nqueens nqueens(size);
    nqueens.solve();
    return 0;
}
