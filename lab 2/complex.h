#pragma once
class Complex
{
public:
	Complex(double re, double im);
	Complex(Complex& com);
	void create(double re, double im);
	void mult_real(double re);
	void add_complex(double re, double im);
	void mult_complex(Complex B);
	void print_length();
	void print();
private:
	double real, imaj;
};
