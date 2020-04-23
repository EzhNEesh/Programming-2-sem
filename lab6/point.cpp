#include "point.h"

cPoint::cPoint(const float a, const float b) :
	x(a), y(b) {}

float cPoint::get_x() { return x; }

float cPoint::get_y() { return y; }