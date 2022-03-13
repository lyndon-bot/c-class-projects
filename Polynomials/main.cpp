#include <iostream>
#include "header.h"
#include <cmath>

using namespace std;



Polynomial::Polynomial(int d){

degree = d;

coef = new double[degree + 1];

    for(int i = 0; i<= degree; i++){
        coef[i] = d;
        //cout << coef[i] << endl;
    }

}

Polynomial::Polynomial(double d[], int deg){

degree = deg;

coef = new double[degree + 1];

    for(int i = 0; i<= degree; i++){
        coef[i] = d[i];
        //cout << coef[i] << endl;

    }
}

Polynomial::~Polynomial(){

delete[] coef;

}

Polynomial::Polynomial(const Polynomial & rhs){

this->degree = rhs.degree;
this->coef = new double[degree + 1];

for(int i = 0; i <= degree; i++){

   coef[i] = rhs.coef[i];
}

}

const Polynomial & Polynomial::operator =(Polynomial rhs){

    this->degree = rhs.degree;
    swap(this->coef, rhs.coef);

    return *this;

}

double & Polynomial::operator[](int term){

return coef[term];

}

const double & Polynomial::operator[](int term) const{

return coef[term];

}

double Polynomial::evaluate(double x) const{

    double result = 0.0;

    for(int i = 0; i <= degree; i++){

        result += coef[i] * pow(x,i);
    }
return result;
}

Polynomial operator + (Polynomial & p1, Polynomial & p2){

    if(p1.degree > p2.degree){

        Polynomial test(p1.degree);
        for(int i = 0 ; i <= p1.degree; i++){

            test.coef[i] = p1.coef[i] + p2.coef[i];
        }
        return test;


    }else if(p2.degree > p1.degree){

        Polynomial test(p2.degree);
        for(int i = 0 ; i <= p2.degree; i++){

            test.coef[i] = p1.coef[i] + p2.coef[i];
        }
        return test;

    }else{

        Polynomial test(p1.degree);
        for(int i = 0 ; i <= p1.degree; i++){

            test.coef[i] = p1.coef[i] + p2.coef[i];
        }
        return test;

    }

}

Polynomial operator - (Polynomial & p1, Polynomial & p2){


 if(p1.degree > p2.degree){

        Polynomial test(p1.degree);
        for(int i = 0 ; i <= p1.degree; i++){

            test.coef[i] = p1.coef[i] - p2.coef[i];
        }
        return test;


    }else if(p2.degree > p1.degree){

        Polynomial test(p2.degree);
        for(int i = 0 ; i <= p2.degree; i++){

            test.coef[i] = p1.coef[i] - p2.coef[i];
        }
        return test;

    }else{

        Polynomial test(p1.degree);
        for(int i = 0 ; i <= p1.degree; i++){

            test.coef[i] = p1.coef[i] - p2.coef[i];
        }
        return test;

    }


}

Polynomial operator * (Polynomial & p1, Polynomial & p2){

Polynomial test(p1.degree+p2.degree);

for(int i = 0; i <= (p1.degree +p2.degree); i++){
    test.coef[i] = 0;
}

     if(p1.degree > p2.degree){

            for(int i = 0 ; i <= p1.degree; i++){
                for(int j = 0; j <= p2.degree; j++){
                test.coef[i+j] += p1.coef[i] * p2.coef[j];
                }
            }
            return test;


    }else if(p2.degree > p1.degree){

        for(int i = 0; i <= p1.degree; i++){
            for(int j = 0; j <= p2.degree; j++){

                test.coef[i+j] += p1.coef[i] * p2.coef[j];
            }
        }
        return test;

    }else{

        for(int i = 0 ; i <= p1.degree; i++){
            for(int j = 0; j <= p2.degree; j++){
            test.coef[i+j] += p1.coef[i] * p2.coef[j];
            }
        }
        return test;

    }




}

ostream & operator << (ostream & out, Polynomial & p){


    for(int i = 0; i <= p.degree; i++){

        out << abs(p.coef[i]);

        for(int j = 0; j < i; j++){
            out << "*X";
        }

        if(i < p.degree){

            if(p.coef[i+1] < 0){

                out << " - ";

            }else{

                out << " + ";

            }
        }

    }

    return out << endl;
}

int main()
{
	Polynomial empty;
	double one[] = {1};
	Polynomial One(one, 0);

	double quad[] = {3, 2, -1};
	double cubic[] = {1, -2, 0, 3};
	Polynomial q(quad, 2); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 3);// c is 1 + 2*x + 0*x*x + 3*x*x*x


	cout << "q = " << q << endl;
	cout << "c = " << c << endl;


	Polynomial p(q);  // test copy constructor (deep copy)
	Polynomial r;
	r = q;             //test operator=
	r = c;

	cout << "Polynomial q = " << q << endl;

	cout << "Polynomial c = " << c << endl;


	cout << "value of q(2) is " << noshowpos << q.evaluate(2) << endl;
	cout << "value of p(2) is " << noshowpos << p.evaluate(2) << endl;
	cout << "value of r(2) is " << noshowpos << r.evaluate(2) << endl;
	cout << "value of c(2) is " << noshowpos << c.evaluate(2) << endl;

	r = q + c;
	cout << "Polynomial q + c = " << r << endl;
	cout << "value of (q + c)(2) is " << r.evaluate(2) << endl;

	r = q - c;
	cout << "Polynomial q-c =  " << r << endl;
	cout << "value of (q - c)(2) is " << r.evaluate(2) << endl;

	r = q * c;
	cout << "q * c = " << r << endl;

	cout << "value of (q * c)(2) is " << r.evaluate(2) << endl;

	//system("pause");

	return 0;
}
