#include "complex.h"
#include "Menu.h"
#include <iostream>

using namespace std;

Complex::Complex(double re = 1, double im = 1) :
	real(re), imaj(im) {}
Complex::Complex(Complex& com) :
	real(com.real), imaj(com.imaj) {}

void Complex::create(double re, double im)
{
	real = re;
	imaj = im;
}
void Complex::mult_real(double re)
{
	real *= re;
	imaj *= re;
	cout << "Answer: ";
	print();
}
void Complex::add_complex(Complex B)
{
	real += B.real;
	imaj += B.imaj;
	cout << "Answer: ";
	print();
}
void Complex::mult_complex(Complex B)
{
	double countReal = real;
	real = real * B.real - imaj * B.imaj;
	imaj = countReal * B.imaj + imaj * B.real;
	cout << "Answer: ";
	print();
}
void Complex::print_length()
{
	cout << sqrt(real * real + imaj * imaj) << endl;
}
void Complex::print()
{
	if (real != 0)
	{
		if (imaj > 0)
			cout << real << '+' << imaj << 'i' << endl;
		else if (imaj == 0)
			cout << real << endl;
		else
			cout << real << imaj << 'i' << endl;
	}
	else if (imaj != 0)
	{
		cout << imaj << 'i' << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}

Menu::Menu() 
{

};

void Menu::command_Menu()
{
	Complex A(1, 1);
	Complex B(A);
	cout << "List of commands:" << endl;
	cout << "1. Create a new complex number;" << endl;
	cout << "2. Multiplication by real number;" << endl;
	cout << "3. Addition of two complex numbers;" << endl;
	cout << "4. Multiplication of two complex numbers;" << endl;
	cout << "5. Count the length;" << endl;
	cout << "6. Print complex number;" << endl;
	cout << "7. Exit;" << endl;
	cout << "Choose a command: ";
	cin >> k;
}
void Menu::command_Execution()
{
	while (k != 7)
	{
		switch (k)
		{
		case 1:
		{
			double re, im;
			cout << "Enter the real part of number: ";
			cin >> re;
			cout << "Enter the imaj part of number: ";
			cin >> im;
			A.create(re, im);
			break;
		}
		case 2:
		{
			double re;
			cout << "Enter the real number: ";
			cin >> re;
			A.mult_real(re);
			break;
		}
		case 3:
		{
			double re, im;
			cout << "Enter the real part of second number: ";
			cin >> re;
			cout << "Enter the imaj part of second number: ";
			cin >> im;
			B.create(re, im);
			A.add_complex(B);
			break;
		}
		case 4:
		{
			double re, im;
			cout << "Enter the real part of second number: ";
			cin >> re;
			cout << "Enter the imaj part of second number: ";
			cin >> im;
			B.create(re, im);
			A.mult_complex(B);
			break;
		}
		case 5:
		{
			cout << "Length of complex numper: ";
			A.print_length();
			break;
		}
		case 6:
		{
			cout << "Complex number: ";
			A.print();
			break;
		}
		default:
			cout << "Uknown command" << endl;
		}
		cout << endl << "Enter a new command: ";
		cin >> k;
	}
}
