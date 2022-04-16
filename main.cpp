#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

	Complex a(41, 55);
	Complex b = a;
	Complex c;

	cout << b.getRe() << endl;
	cout << b.getIm() << endl;
	cout << b << endl;

	cout << "input complex number (Re Im): ";
	cin >> c;
	cout << endl << "c = " << c << endl;

	cout << "a + c = " << a + c << endl;
	cout << "a - c = " << a - c << endl;
	cout << "a * c = " << a * c << endl;
	cout << "a / c = " << a / c << endl;

	cout << "module c = " << c.absC() << endl;

	cout << endl << "c^n(int) = " << c.powC() << endl;

	cout << "trigonometric form: ";
	c.trigonometric();

	return 0;
}
