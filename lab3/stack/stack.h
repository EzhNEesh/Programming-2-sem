#pragma once
#include <iostream>

class cstack
{
public:
	cstack();
	cstack(const size_t& new_size);
	~cstack();
	bool operator << (const int& instack);
	int operator >> (int);
	void outstack();

private:
	int* data;
	size_t size;
	int pos;
};