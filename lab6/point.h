#pragma once

class cPoint
{
public:
	cPoint(const float a, const float b);
	float get_x();
	float get_y();
private:
	float x, y;
};