#pragma once

bool predicateFloat(float a)
{
	return a < 0;
}

bool compareFloat(float a0, float a1)
{
	return a0 < a1;
}

bool eqFloat(float a, float value)
{
	return (a == value);
}

bool predicatePoint(cPoint point)
{
	return (point.get_x() < 0.0) && (point.get_y() < 0.0);
}

bool comparePoints(cPoint point0, cPoint point1)
{
	return (point0.get_x() <= point1.get_x()) && (point0.get_y() <= point1.get_y());
}

bool eqPoints(cPoint point, cPoint value)
{
	return (point.get_x() == value.get_x()) && (point.get_y() == value.get_y());
}