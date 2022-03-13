#include <iostream>
#include <vector>
#include "ChessPuzzle.h"
#include <time.h>
#include <stdlib.h>

ChessPuzzle::ChessPuzzle(int num){

N = num;

board = vector< vector<int> >(num);

for(int i = 0; i < num; i++){

    board[i] = vector<int>(num);
}

for(int i = 0; i < num; i++){
    for(int j = 0; j < num; j++){

    board[i][j] = 0;

    }
}

}

    //initializes all entries to 0

void ChessPuzzle::printBoard() const{

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

        cout << board[i][j];

        }
        cout << endl;
    }

}


bool ChessPuzzle::canPlaceQueen(int row, int col){

    for(int offset = 1; offset <= row; offset++){

        if(board[row-offset][col] == 1){
            return false;
        }

        if(inBoard(row-offset,col-offset)){

            if(board[row-offset][col-offset] == 1){
                return false;
            }
        }

        if(inBoard(row-offset,col+offset)){

            if(board[row-offset][col+offset] == 1){
                return false;
            }
        }

    }

    return true;
}

bool ChessPuzzle::inBoard(int row, int col){

    if(row >= N || row < 0 || col >= N || col < 0){

        return false;

    }else{

        return true;

    }

}

void ChessPuzzle::eightQueens(int row, int & solutions){

   if(row > N-1){

        solutions++;
        cout << "Found " << N << "-queens solution # " << solutions << endl;
        printBoard();

   }else{

        for(int col = 0; col < N; col++){
            if(canPlaceQueen(row,col)){
                board[row][col] = 1;
                eightQueens(row + 1, solutions);
                board[row][col] = 0;
            }
        }
   }


}


int main()
{
	int num;
	cout << "Enter the size of the board: ";
	cin >> num;

	ChessPuzzle myPuzzle(num);

    int numberOfSolutions = 0;

	myPuzzle.eightQueens(0, numberOfSolutions);


	return 0;
}
