#include <iostream>

using namespace std;

int factorial (int n){

    if (n==0){
        return 1;
    }else{

        int subN = n-1;
        int subFact = factorial(subN);
        return n * subFact;

    }

}

double pow(double a, int n){

    if(n == 0){
        return 1;
    }else{
        cout << n << endl;
        return a*pow(a,n-1);
    }
}


void print(int n){

    if(n < 10){
        cout << n << " ";
    }else {

        print(n/10);
        cout << n %10 << " ";


    }
}

void printReverse(int n){

    if(n < 10){
        cout << n << " ";
    }else {


        cout << n %10 << " ";
        print(n/10);

    }
}

void hanoi(int n, int a, int b, int c){

    if( n==1){
        cout << a << "-- >" << c<< endl;
    }else{

        hanoi(n-1, a,b,c);

        cout << a << "-- > " << c << endl;
        hanoi(n-1, b,a,c);




    }

}

int main()
{
    int num;

    cout << "Enter a number";
    cin >> num;

    cout << "the digits are:";
    print(num);

    cout << "the reverse digits are";
    printReverse(num);

    return 0;
}
