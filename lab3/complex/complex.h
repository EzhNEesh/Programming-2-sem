#pragma once

class ccomplex
{
public:
	ccomplex();
	ccomplex(const double& _real, const double& _imaj);
	ccomplex(const ccomplex& com);

	friend std::ostream& operator << (std::ostream& out, const ccomplex& outcom);
	friend std::istream& operator >> (std::istream& in, ccomplex& incom);
	ccomplex operator * (const double& a);
	ccomplex operator * (const ccomplex& com);
	ccomplex operator + (const ccomplex& com);
	operator double ();

private:
	double imaj;
	double real;
};