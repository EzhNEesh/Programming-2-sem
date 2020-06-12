#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
	ccomplex aa;
	double bb;
	cout << "Enter a numbers of complex: ";
	cin >> aa;
	cout << "Enter a double: ";
	cin >> bb;
	cout << '(' << aa << ")*" << bb << '=' << aa * bb << endl;
	cout << '(' << aa << ")*" << bb << '=' << aa.operator*(bb) << endl << endl;

	ccomplex a, b;
	cout << "Enter a numbers of first complex: ";
	cin >> a;
	cout << "Enter a numbers of first complex: ";
	cin >> b;
	cout << '(' << a << ")*(" << b << ")=" << a * b << endl;
	cout << '(' << a << ")*(" << b << ")=" << a.operator*(b) << endl << endl;
	cout << '(' << a << ")+(" << b << ")=" << a + b << endl;
	cout << '(' << a << ")+(" << b << ")=" << a.operator+(b) << endl << endl;

	ccomplex m;
	cout << "Enter a numbers of first complex: ";
	cin >> m;
	cout << (double)m << endl;
	cout << m.operator double() << endl << endl;
	return 0;
}