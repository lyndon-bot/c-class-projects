#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "header.h"

using namespace std;

int KnightTour::access(){

    for(int i = 0; i<8; i++){

        for(int z = 0; z<8; z++){

            if(i < 2){
                if(z < 2){
                     pos[i][z] = i + z + 2;
                }else if(z >= 2 && z <= 5){
                     pos[i][z] = (i+2)*2;
                }else if(z == 6){
                     pos[i][z] = pos[i][z] = pos[i][z-5];
                }else {
                     pos[i][z] = pos[i][z] = pos[i][z-z];
                }
            }else if(i >= 2 && i <= 5){

                if(z == 0){
                    pos[i][z] = 4;
                }else if(z == 1){
                    pos[i][z] = 6;
                }else if(z >= 2 && z <= 5){
                     pos[i][z] = 8;
                }else if(z == 6){
                     pos[i][z] =  6;
                }else {
                     pos[i][z] =  4;
                }

            } else if(i == 6){
                if(z < 2){
                     pos[i][z] = (i-5) + z + 2;
                }else if(z >= 2 && z <= 5){
                     pos[i][z] = ((i-5)+2)*2;
                }else if(z == 6){
                     pos[i][z] = pos[i][z] = pos[i][z-5];
                }else {
                     pos[i][z] = pos[i][z] = pos[i][z-z];
                }

            }else{

                if(z < 2){
                     pos[i][z] = (i-7) + z + 2;
                }else if(z >= 2 && z <= 5){
                     pos[i][z] = ((i-7)+2)*2;
                }else if(z == 6){
                     pos[i][z] = pos[i][z] = pos[i][z-5];
                }else {
                     pos[i][z] = pos[i][z] = pos[i][z-z];
                }


            }

          }

        }

}

 int KnightTour::initialize(){

    for(int i = 0; i<8; i++){

        for(int z = 0; z<8; z++){

            board[i][z] = 0;
        }

    }

    access();

return 0;
 }

int KnightTour::getKightTour(){

initialize();
int step = 1;
board[x][y] = step;

int horizontal[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int vertical[8] = {1, -1, 2, -2, 1, -1, 2, -2};

 for(int i=0; i<8; i++){


         int testx = x + horizontal[i];
         int testy = y + vertical[i];

         if(testx < 0 || testx > 7 || testy < 0 || testy > 7 || board[testx][testy] != 0){

         movea[i] = 0;
         movex[i] = 0;
         movey[i] = 0;

         }else{

         movea[i] = pos[testx][testy];
         movex[i] = testx;
         movey[i] = testy;

        }
    }

while(step < 64){
    printAccess();
    printBoard();
    updateAccess(x,y);
    nextMove();
    step++;
    board[x][y] = step;
}

printAccess();
printBoard();


return 0;
}


//If a knight is placed at[x][y], all the squares reachable to [x][y] lose one access
int KnightTour::updateAccess(int x, int y){

    for(int i =0; i<8; i++){

        if(movea[i]!=0){
            pos[movex[i]][movey[i]]--;
        }
    }
return 0;
}

int KnightTour::nextMove(){

    int horizontal[8] = {2, 2, 1, 1, -2, -2, -1, -1};
    int vertical[8] = {1, -1, 2, -2, 1, -1, 2, -2};

    for(int i=0; i<8; i++){

         int testx = x + horizontal[i];
         int testy = y + vertical[i];

         if(testx < 0 || testx > 7 || testy < 0 || testy > 7 || board[testx][testy] != 0){

         movea[i] = 0;
         movex[i] = 0;
         movey[i] = 0;

         }else{

         movea[i] = pos[testx][testy];
         movex[i] = testx;
         movey[i] = testy;

        }
    }

  //  cout << "current position" << x << y << endl;

/*
    for(int i=0; i<8; i++){

        cout << "move #" << i << endl;
        cout << movea[i] << endl;
        cout << movex[i] << endl;
        cout << movey[i] << endl;

    }*/
    small();

return 0;
}

int KnightTour::small(){

int smallest;
int smallx = 0;
int smally = 0;

for(int i=0;i<8;i++){

    if(movea[i] != 0){

        smallest = movea[i];
        smallx = movex[i];
        smally = movey[i];
        break;

    }
}

for(int i=0;i<8;i++){

    if(movea[i] < smallest && movea[i] != 0){
       smallest = movea[i];
       smallx = movex[i];
       smally = movey[i];
    }


}

x = smallx;
y = smally;
/*
cout << "small" << smallest << smallx <<  smally << endl;
cout << "New Move" << pos[x][y] << x << y << endl;
*/

return 0;

}

//bool KnightTour::inBoard(int x, int y);

void KnightTour::printBoard(){

    for(int i = 0; i < 8 ; i++){
            for(int j = 0; j< 8; j++)
            {
                cout << setw(4) << board[i][j];
            }

        cout << endl;
    }

}

void KnightTour::printAccess(){

 for(int i = 0; i<8; i++){

        for(int z = 0; z<8; z++){

            cout << pos[i][z];
        }
        cout << endl;

    }


}

int main()
{

    KnightTour tour;
    tour.getKightTour();
    return 0;
}
