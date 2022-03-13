#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h";

using namespace std;

void knightstour::access(){
    //int access(int x, int y)

    //int pos[8][8] = {};

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

int knightstour::jump(){

int horizontal[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int vertical[8] = {1, -1, 2, -2, 1, -1, 2, -2};

for(int i=0; i<8; i++){

 int x = posx + horizontal[i];
 int y = posy + vertical[i];

 if(x < 0 || x > 7 || y < 0 || y > 7){

 movea[i] = 0;
 movex[i] = 0;
 movey[i] = 0;

 }else{

 movea[i] = pos[x][y];
 movex[i] = x;
 movey[i] = y;

    }
}

cout << "current position" << posx << posy << endl;


for(int i=0; i<8; i++){

    cout << "move #" << i << endl;
    cout << movea[i] << endl;
    cout << movex[i] << endl;
    cout << movey[i] << endl;

    }
}

int knightstour::small(){

int smallest;
int smallx;
int smally;

for(int i=0;i<8;i++){

    if(movea[i] != 0){

        smallest = movea[i];
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

pos[posx][posy] = 0;
posx = smallx;
posy = smally;

cout << "small" << smallest << smallx <<  smally << endl;
cout << "New Move" << pos[posx][posy] << posx << posy << endl;


return 0;

}

int knightstour::print(){

for(int i = 0; i<8; i++){

        for(int z = 0; z<8; z++){

            cout << pos[i][z];
        }
        cout << endl;

    }

return 0;
}

int knightstour::start(){

srand(time(NULL));
posx = 0;
posy = 0;

//posx = rand() %8;
//posy = rand() %8;
access();
return 0;

}


int main()
{
knightstour tour;
tour.start();

for(int i =0;i<64;i++){

    tour.jump();
    tour.small();
    tour.print();

}



return 0;
}
