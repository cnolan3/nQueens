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
    bool solveRecurse(int);
    void print();

  private:
    std::vector< std::vector<int> > grid;
    int size;
};
#endif
