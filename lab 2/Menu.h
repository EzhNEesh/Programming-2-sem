#pragma once
#include "complex.h"

class Menu
{
private:
	int k;
	Complex A;
	Complex B;
	
public:
	Menu();
	void command_Menu();
	void command_Execution();
};
