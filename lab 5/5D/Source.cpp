#include <iostream>
#include "function.h"

using namespace std;

int main()
{
	char type[20];
	cout << "Enter type: ";
	gets_s(type);
	if (type[0] == 'i')
	{
		int N, deg;
		cout << "Enter variable: "; 
		cin >> N;
		cout << "Enter degree: ";
		cin >> deg;
		cout << VarDeg<int>(deg, N);
	}
	else if (type[0] == 'f')
	{
		float N;
		int deg;
		cout << "Enter variable: "; 
		cin >> N;
		cout << "Enter degree: ";
		cin >> deg;
		cout << VarDeg<float>(deg, N);
	}
	else if (type[0] == 'd')
	{
		double N;
		int deg;
		cout << "Enter variable: ";
		cin >> N; 
		cout << "Enter degree: ";
		cin >> deg;
		cout << VarDeg<double>(deg, N);
	}
	else if (type[0] == 'u')
	{
		if (type[9] == 'i')
		{
			unsigned int N;
			int deg;
			cout << "Enter variable: ";
			cin >> N;
			cout << "Enter degree: ";
			cin >> deg;
			cout << VarDeg<unsigned int>(deg, N);
		}
		else if (type[9] == 'l')
		{
			cin >> type;
			if (type[9] == 'i')
			{
				unsigned long int N;
				int deg;
				cout << "Enter variable: ";
				cin >> N; 
				cout << "Enter degree: ";
				cin >> deg;
				cout << VarDeg<unsigned long int>(deg, N);
			}
			else if (type[9] == 'l')
			{
				unsigned long long N;
				int deg;
				cout << "Enter variable: ";
				cin >> N;
				cout << "Enter degree: ";
				cin >> deg;
				cout << VarDeg<unsigned long long>(deg, N);
			}
		}
	}
	else if (type[0] == 'l')
	{
		if (type[5] == 'i')
		{
			long int N;
			int deg;
			cout << "Enter variable: "; 
			cin >> N;
			cout << "Enter degree: ";
			cin >> deg;
			cout << VarDeg<long int>(deg, N);
		}
		else if (type[5] == 'l')
		{
			long long N;
			int deg;
			cout << "Enter variable: "; 
			cin >> N;
			cout << "Enter degree: ";
			cin >> deg;
			cout << VarDeg<long long>(deg, N);
		}
		else if (type[5] == 'd')
		{
			long double N;
			int deg;
			cout << "Enter variable: ";
			cin >> N;
			cout << "Enter degree: ";
			cin >> deg;
			cout << VarDeg<long double>(deg, N);
		}
	}
	else
	{
		cout << "ERROR: uknown type of variable..." << endl;
	}
	return 0;
}