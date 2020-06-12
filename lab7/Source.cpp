#include <iostream>
#include <algorithm>
#include "CircBuffer.h"

using namespace std;

int main()
{
	CircularBuffer<int> myCirc(5);
	myCirc.push_back(1);
	myCirc.push_back(2);
	myCirc.push_back(3);
	myCirc.push_back(4);
	myCirc.push_back(5);
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	myCirc.push_back(6);
	myCirc.pop_back();
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;

	myCirc.resize(10);
	myCirc.push_back(7);
	myCirc.push_back(8);
	myCirc.push_back(9);
	myCirc.push_back(10);
	myCirc.push_back(11);
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;

	myCirc.push_begin(12);
	myCirc.push_begin(13);
	myCirc.push_begin(14);
	myCirc.push_begin(15);
	myCirc.push_begin(16);
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;

	myCirc.pop_back();
	myCirc.pop_begin();
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;

	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;

	myCirc.insert(myCirc.begin() + 1, 33);
	myCirc.insert(myCirc.end() - 3, 22);
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;

	myCirc.erase(myCirc.begin());
	myCirc.erase(myCirc.begin() + 3);
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;
	return 0;
}
