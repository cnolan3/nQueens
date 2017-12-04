#include"nqueens.h"
using namespace std;

Nqueens::Nqueens(const int s)
{
  size = s;
  grid.resize(s, vector<int>(s));
}

Nqueens::~Nqueens()
{
}

bool Nqueens::checkSafe(int row, int col)
{
    int i, j;

    for(i = 0; i < col; i++) {
        if(grid[row][i] == 1) {
            return false;
        }
    }

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(grid[i][j] == 1) {
            return false;
        }
    }

    for(i = row, j = col; i < size && j >= 0; i++, j--) {
        if(grid[i][j] == 1) { 
            return false;
        }
    }

    return true;
}

void Nqueens::solve()
{
    if(!solveRecurse(0)) {
        cout << "no solution" << endl;
        return;
    }

    cout << "Finished---------------------------------------" << endl;
    print();
}

bool Nqueens::solveRecurse(int col)
{
    if(col >= size) {
        return true;
    }

    for(int i = 0; i < size; i++) {
        if(checkSafe(i, col) == true) {
            grid[i][col] = 1;
            cout << col << "----------------------------------------------" << endl;
            print();

            if(solveRecurse(col + 1) == true) {
                return true;
            }

            grid[i][col] = 0;
        }
    }
    return false;
}

void Nqueens::print()
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

