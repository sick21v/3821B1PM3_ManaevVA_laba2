#include <iostream>
#include <math.h>
#include "Complex.h"

using namespace std;

Complex::Complex()
{
	Re = 0;
	Im = 0;
}

Complex::Complex(double Re, double Im)
{
	this->Re = Re;
	this->Im = Im;
}

Complex::Complex(const Complex& value)
{
	Re = value.Re;
	Im = value.Im;
}

double Complex::getRe()
{
	return Re;
}

double Complex::getIm()
{
	return Im;
}

void Complex::setRe(double valueRe)
{
	this->Re = valueRe;
}

void Complex::setIm(double valueIm)
{
	this->Im = valueIm;
}

Complex Complex::operator+(Complex value)
{
	return Complex(this->Re + value.Re, this->Im + value.Im);
}

Complex Complex::operator-(Complex value)
{
	return Complex(this->Re - value.Re, this->Im - value.Im);
}

Complex Complex::operator*(Complex value)
{
	return Complex((this->Re * value.Re) - (this->Im * value.Im), (this->Re * value.Im) + (value.Re * this->Im));
}

Complex Complex::operator/(Complex value)
{
	double rRe = ((this->Re * value.Re) + (this->Im * value.Im)) / (pow(value.Re, 2) + pow(value.Im, 2));
	double rIm = ((value.Re * this->Im) - (this->Re * value.Im)) / (pow(value.Re, 2) + pow(value.Im, 2));

	return Complex(rRe, rIm);
}

Complex& Complex::operator=(Complex value)
{
	Re = value.Re;
	Im = value.Im;

	return *this;
}

bool Complex::operator==(Complex value)
{
	if (this->Re == value.Re && this->Im == value.Im)
	{
		return true;
	}

	else return false;
}

ostream& operator<<(ostream& output, Complex value)
{
	output << value.Re << (value.Im >= 0 ? " + " : " - ") << abs(value.Im) << "i" << endl;

	return output;
}

istream& operator>>(istream& input, Complex& value)
{
	input >> value.Re;
	input >> value.Im;

	return input;
}

double Complex::absC()
{
	return sqrt(pow(this->Re, 2) + pow(this->Im, 2));
}

Complex Complex::powC()
{	
	double powC = 0;
	cout << "input degree(int): ";
	cin >> powC;

	return Complex(pow(this->absC(), powC)*cos(powC*argC()), pow(this->absC(), powC)*sin(powC*argC()));
}

void Complex::trigonometric()
{
	cout << this->absC() << "*(cos(" << argC() << ") + i*sin(" << argC() << ")" << endl;
}

double Complex::argC()
{
	double phi = 0;
	double pi = 3.14159;

	if (this->Re > 0)
	{
		phi = atan2(this->Im, this->Re);
	}

	else if (this->Re < 0 && this->Im >= 0)
	{
		phi = atan2(this->Im, this->Re) + pi;
	}

	else if (this->Re < 0 && this->Im < 0)
	{
		phi = atan2(this->Im, this->Re) - pi;
	}

	else if (this->Re == 0 && this->Im > 0)
	{
		phi = pi/2;
	}

	else if (this->Re == 0 && this->Im < 0)
	{
		phi = -pi / 2;
	}

	else
	{
		cout << "Error" << endl;
		return 0;
	}


	return phi;
}
