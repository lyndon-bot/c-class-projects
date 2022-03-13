#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED


#include <iostream>

using namespace std;

class Rational
{
public:
	//Specify default argument values in one place only (.h or .cpp, but not both)
	Rational(int a = 1, int b = 1);

	const Rational operator + (Rational & rhs);
	const Rational operator - (Rational & rhs);

	const Rational operator * (Rational & rhs);
	const Rational operator / (Rational & rhs);

	void reduce();

	int gcd(int x, int y);

	void print();

	//non-member friend functions
	friend istream & operator >> (istream & in, Rational & r);
	friend ostream & operator << (ostream & out, Rational & r);


private:
	int n;
	int d;
}; //Do not forget this ;


#endif // RATIONAL_H_INCLUDED
