#include <iostream>
#include "complex.h"

using namespace std;

ccomplex::ccomplex() : real(0), imaj(0) {};
ccomplex::ccomplex(const double& _real, const double& _imaj) : real(_real), imaj(_imaj) {};
ccomplex::ccomplex(const ccomplex& com) : real(com.real), imaj(com.imaj) {};

std::ostream& operator << (std::ostream& out, const ccomplex& outcom)
{
	if (outcom.real != 0)
		out << outcom.real;
	if (outcom.imaj > 0)
		out << '+' << outcom.imaj << 'i';
	else if (outcom.imaj < 0)
		out << outcom.imaj << 'i';
	return out;
}

std::istream& operator >> (std::istream& in, ccomplex& incom)
{
	in >> incom.real >> incom.imaj;
	return in;
}

ccomplex ccomplex:: operator * (const double& a)
{
	return ccomplex(real * a, imaj * a);
}

ccomplex ccomplex:: operator * (const ccomplex& com)
{
	double buf_real = real * com.real - imaj * com.imaj;
	double buf_imaj = imaj * com.real + real * com.imaj;
	return ccomplex(buf_real, buf_imaj);
}

ccomplex ccomplex:: operator + (const ccomplex& com)
{
	return ccomplex(real + com.real, imaj + com.imaj);
}

ccomplex::operator double()
{
	return sqrt(imaj * imaj + real * real);
}