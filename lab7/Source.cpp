#include <iostream>
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

	myCirc.erase(8);
	myCirc.erase(9);
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;

	myCirc.insert(0, 99);
	myCirc.insert(1, 100);
	for (size_t i = 0; i < myCirc.size(); i++)
	{
		cout << myCirc[i] << ' ';
	}
	cout << endl;
	return 0;
}