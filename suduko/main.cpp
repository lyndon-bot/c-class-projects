#include <iostream>
#include "spot.h"
#include "Sudoku.h"
#include <algorithm>


//constructor
Spot::Spot(int x, int y)
{
	this->row = x; // explicit calling
	col = y; // implicit calling
}

//copy constructor
/*Spot::Spot(const Spot &s1)
{
	this->row = s1.row;
	this->col = s1.col;
}*/

//place digit
void Spot::placeDigit(int d, int grid[9][9])
{
	grid[row][col] = d;
}

// accessor
vector<int> Spot::getCandidateDigits() const
{
	return candidateDigits;
}

//Given a single digit can I place it in a partially filled grid
bool Spot::isValidDigit(int d, int grid[9][9]) const
{
	//check if there is any other d in the same row
	for (int i = 0; i<9; i++)
	{
		if (grid[row][i] == d)
		{
			return false;
		}
	}

	//check if there is any other d in the same column
	for (int i = 0; i<9; i++)
	{

		if (grid[i][col] == d)
		{
			return false;
		}
	}

	//check if there is any other d in the same square
	int startx = row / 3 * 3;
	int starty = col / 3 * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[startx + i][starty + j] == d)
				return false;
		}
	}

	return true;
}

//computes digits initially
void Spot::computeCandidateDigits(int grid[9][9])
{
	for (int digit = 1; digit < 10; digit++)
	{
		if (this->isValidDigit(digit, grid))
			this->candidateDigits.push_back(digit);
	}
	//sorts digits
	sort(candidateDigits.begin(), candidateDigits.end());
}

//computes digits during runtime
/*void Spot::computeCandidateDigits(int grid[9][9], vector<int> candidates)
{
	for (int c1 = 0; c1 < candidates.size(); c1++)
	{
		if (this->isValidDigit(candidates[c1], grid))
			this->candidateDigits[c1] = candidates[c1];
	}
}*/

//we can call the sort routine from <algorithm>
bool Spot::operator < (const Spot & rhs) const
{
	return this->candidateDigits.size() < rhs.candidateDigits.size();
}

//assignment operator
/*Spot& Spot::operator= (const Spot & rhs)
{
	this->row = rhs.row;
	this->col = rhs.col;

	return this;
}*/

Sudoku::Sudoku(string sfile){

    ifstream infile(sfile.c_str());

	if (!infile)
	{
		cerr << "Error opening sudoku file" << endl;

		exit(1);
	}

	int count = 0;
	//initializes grid from input file
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//offsets string to num
			infile >> grid[i][j];

			//fills in vector of empty spots
			if (grid[i][j] == 0)
			{
				this->emptySpots.push_back(Spot(i, j));
				count++;
			}
		}
	}

	//some printout would be good here
	printGrid();
	cout << "Number of empty spots: " << count << endl;

	//computes the digits for each empty spot
	for (int i = 0; i < count; i++)
	{
		emptySpots[i].computeCandidateDigits(grid);
	}

	//sorts vector by size of candidates list
	//uses built in sort for <algorithm>
	sort(emptySpots.begin(), emptySpots.end());

}

void Sudoku::printGrid() const {
//prints out grid
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << grid[i][j] << " ";
			if (j % 3 == 2 && j != 8)
				cout << " | ";
		}
		cout << endl;
		if (i % 3 == 2 && i != 8)
			cout << "------ | ------ | ------" << endl;
	}
}

void Sudoku::solve(int N)
{
	//base case
	if (emptySpots.size() == N)
	{
		printGrid();

	}

	vector<int> mydigits = emptySpots[N].getCandidateDigits();

	for (int i = 0; i < mydigits.size(); i++)
	{
		if (emptySpots[N].isValidDigit(mydigits[i], grid))
		{
			emptySpots[N].placeDigit(mydigits[i], grid);
			solve(N + 1);
			emptySpots[N].placeDigit(0, grid);
		}
	}

	//places a candidate digit, goes further until either deadend, or finished
	/*for (int i = 0; i < emptySpots[N].getCandidateDigits.size(); i++)
	{
		emptySpots[N].placeDigit(emptySpots[N].getCandidateDigits[i], grid);
		emptySpots[N + 1].computeCandidateDigits(grid, emptySpots[N + 1].getCandidateDigits());
		solve(N + 1);
	}*/
}

using namespace std;

int main()
{
    string file;

	cout << "Please enter sudoku file: ";
	cin >> file;

	Sudoku s1(file);

	s1.solve(0);
	return 0;

}
