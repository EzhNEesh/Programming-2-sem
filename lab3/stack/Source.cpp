#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	cstack a;
	cout << "Choose com:\n"
		<< "1. Push in stack;\n"
		<< "2. Pop from stack;\n"
		<< "3. Out stack;\n"
		<< "4. Exit;\n";
	int k;
	cin >> k;
	while (k != 4)
	{
		if (k == 1)
		{
			int d;
			cin >> d;
			a << d;
			a.operator<<(d);
		}
		else if (k == 2)
		{
			cout << (a >> 0) << endl;
		}
		else if (k == 3)
		{
			a.outstack();
		}
		cin >> k;
	}
	a.outstack();
	return 0;
}