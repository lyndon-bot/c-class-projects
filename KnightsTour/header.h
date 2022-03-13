#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class knightstour{

private:

int pos[8][8];
void access();
int movea[8];
int movex[8];
int movey[8];

public:

int posx, posy;
int jump();
int small();
int start();
int print();
bool inboard();
};



#endif // HEADER_H_INCLUDED
