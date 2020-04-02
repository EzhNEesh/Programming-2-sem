#include <iostream>
#include "class.h"

using namespace std;

int main()
{
	queue<10, int> New;
	string kom;
	while (1)
	{
		cin >> kom;
		if (kom == "push")
		{
			int D;
			cin >> D;
			try
			{
				New.push(D);
			}
			catch (qException& ex)
			{
				cout << ex.getError() << endl;
			}
		}
		else if (kom == "pop")
		{
			try
			{
				cout << New.pop() << endl;
			}
			catch (qException& ex)
			{
				cout << ex.getError() << endl;
			}
		}
		else if (kom == "exit")
		{
			return 0;
		}
		else
		{
			cout << "Uknown kommand" << endl;
		}
	}
}