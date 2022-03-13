#ifndef SPOT_H_INCLUDED
#define SPOT_H_INCLUDED
#include <vector>


using namespace std;

class Spot{

public:
    Spot(int x = 0, int y = 0);
    bool isValidDigit(int d, int grid[9][9]) const; // const means it wont change any values

    vector<int> getCandidateDigits() const; //accessor

    void computeCandidateDigits(int grid[9][9]);

    void placeDigit(int d, int grid[9][9]);

    //overload operator < to make spot object comparable

    bool operator < (const Spot & rhs) const;

private:
    int row;
    int col;
    vector<int> candidateDigits;


};

#endif // SPOT_H_INCLUDED
