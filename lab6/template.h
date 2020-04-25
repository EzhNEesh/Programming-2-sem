#pragma once
#include <vector>

template<class T, class F>
bool all_of(T start, T end, F fun)
{
	while (start != end)
	{
		if (!fun(*start))
			return false;
		start++;
	}
	return true;
}

template<class T, class F>
bool is_sorted(T start, T end, F fun)
{
	while (start + 1 != end)
	{
		if (!fun(*start, *(start + 1)))
			return false;
		start++;
	}
	return true;
}

template<class T, class TV, class F>
T find_backward(T start, T end, TV des_value, F fun)
{
	T count = end;
	count--;
	while (count != start)
	{
		if (fun(*count, des_value))
			return count;
		count--;
		if (count == start)
			break;
	}
	return end;
}
