#pragma once
class Complex
{
public:
	Complex();
	void create(double re, double im);
	void mult_real(double re);
	void add_complex(double re, double im);
	void mult_complex(double re, double im);
	void print_length();
	void print();
private:
	double real, imaj;
};