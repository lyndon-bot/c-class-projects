#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED
#include "spot.h"
#include <string>
#include <fstream>
#include <iostream>

class Sudoku{

private:
     int grid[9][9];
     vector< Spot > emptySpots;


public:

    Sudoku(string  sfile);
    void solve(int N); // recursive Solve the Puzzle
    void printGrid() const;


};


#endif // SUDOKU_H_INCLUDED
