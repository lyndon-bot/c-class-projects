#ifndef CHESSPUZZLE_H_INCLUDED
#define CHESSPUZZLE_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

class ChessPuzzle
{
public:
	ChessPuzzle(int num = 8); //initializes all entries to 0

	void printBoard() const;

	bool canPlaceQueen(int row, int col);
	bool inBoard(int row, int col);

	void eightQueens(int row, int & solutions);

private:
	vector< vector<int> > board;
	int N;
};



#endif // CHESSPUZZLE_H_INCLUDED
