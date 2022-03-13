
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

using namespace std;

class Polynomial
{
public:
	Polynomial(int d = 0);
	Polynomial(double d[], int degree);

	//copy constructor
	Polynomial(const Polynomial & rhs);
	const Polynomial & operator = (Polynomial rhs);

	//destructor
	~Polynomial();

	int getDegree() const;
	double & operator[](int term);
	//This is required if we are to have const correctness
	const double & operator[](int term) const;

	double evaluate(double x) const; //plug-in x value to evaluate the polynomial expression

	//friend functions
	friend Polynomial operator + (Polynomial & p1, Polynomial & p2);
	friend Polynomial operator - (Polynomial & p1, Polynomial & p2);
	friend Polynomial operator * (Polynomial & p1, Polynomial & p2);
	friend ostream & operator << (ostream & out, Polynomial & p);

private:
	double * coef;
	int degree;
};
#endif

