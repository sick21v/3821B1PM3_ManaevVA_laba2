#pragma once

#include <iostream>

using namespace std;

class Complex
{
public:

	Complex();
	Complex(double Re, double Im);
	Complex(const Complex& value);

	double getRe();
	double getIm();
	void setRe(double valueRe);
	void setIm(double valueIm);

	Complex operator+ (Complex value);
	Complex operator- (Complex value);
	Complex operator* (Complex value);
	Complex operator/ (Complex value);

	Complex& operator= (Complex value);

	bool operator== (Complex value);

	friend ostream& operator<< (ostream& output, Complex value);
	friend istream& operator>> (istream& input, Complex& value);

	double absC(); // complex module

	double argC(); // argument complex

	Complex powC(); // complex raising to an degree (<>0, k = 0)

	void trigonometric(); // trigonometric form of complex

protected:

	double Re;
	double Im;
};