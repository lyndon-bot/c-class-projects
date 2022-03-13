#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class KnightTour
{
public:

	//constructor
    //KnightTour(int x = 0, int y = 0);

    int x =7;
    int y =7;
    int initialize();
    int access();
    int getKightTour();
    int updateAccess(int x, int y);
    int nextMove();
    int small();

    bool inBoard(int x, int y);

    void printBoard();
    void printAccess();

private:
    int board[8][8];
    int pos[8][8];
    int currentx, currenty;
    const static int horizontal[8];
    const static int vertical[8];
    int movea[8];
    int movex[8];
    int movey[8];

};

#endif // HEADER_H_INCLUDED
