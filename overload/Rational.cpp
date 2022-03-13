#include "Rational.h"

Rational::Rational(int a, int b) :n(a) {

    if(b ==0){
        cerr << "Divisor is zero, defaults to 1.\n";
        this -> d = 1;
    }

}

const Rational Rational:operator + (Rational & rhs){

    int a = rhs.n;
    int b = rhs.d;

    //computer = n/d  + a/b

    int nn = n * b + d * a;
    int dd = d * b;

    return Rational(nn,dd);
}
