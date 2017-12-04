#ifndef NQUEENS_H
#define NQUEENS_H
#include<iostream>
#include<vector>

class Nqueens
{
  public:
    Nqueens(int);
    ~Nqueens();
    bool checkSafe(int, int);
    void solve();
    void print();

  private:
    bool solveRecurse(int);

    std::vector<std::vector<int> > grid;
    int size;
};
#endif
