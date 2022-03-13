#include <iostream>

using namespace std;

int main()
{
    double pi = 0.0;

    for(int i=0; i<=100000; i++){

        double term = 4.0;

        if(i%2 == 0){

            pi += term/(2*i+1);

        } else {

            pi -= term/(2*i+1);
        }

        if ((i/1000) >= 1) {

        cout << i << " " << pi << endl;
        }
    }

    cout << pi << endl;
    return 0;
}
