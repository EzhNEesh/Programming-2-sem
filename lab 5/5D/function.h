#pragma once

template<typename VarType>
VarType VarDeg(int deg, VarType x)
{
	VarType y = x;
	x = 1;
	while (deg != 0)
	{
		if (deg > 0)
		{
			deg--;
			x *= y;
		}
		else
		{
			deg++;
			x /= y;
		}
	}
	return x;
}