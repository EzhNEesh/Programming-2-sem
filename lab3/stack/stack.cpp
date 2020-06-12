#include "stack.h"

cstack::cstack() : data(new int[100]), size(100), pos(0) {};
cstack::cstack(const size_t& new_size) : data(new int[100]), size(new_size), pos(0) {};
cstack::~cstack() {	delete[] data;}

bool cstack::operator << (const int& instack)
{
	if (pos == size)
	{
		return false;
	}
	else
	{
		data[pos] = instack;
		pos++;
		return true;
	}
}

int cstack::operator >> (int)
{
	if (pos > 0)
	{
		pos--;
		return data[pos];
	}
	else
	{
		return -1;
	}
}

void cstack::outstack()
{
	if (pos != 0)
	{
		for (int i = 0; i < pos; i++)
			std::cout << data[i] << ' ';
		std::cout << '\n';
	}
	else
	{
		std::cout << "Stack is empty\n";
	}
}