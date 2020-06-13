#include <iostream>
#include "figures.h"
#include <cmath>

triangle::triangle()
{
	center.x = 0;
	center.y = 0;
	vertex.x = 0; 
	vertex.y = 0;
	weight = 0;
};

ellipse::ellipse()
{
	center.x = 0;
	center.y = 0;
	HalfShA.x = 0;
	HalfShA.y = 0;
	HalfShB.x = 0;
	HalfShB.y = 0;
	weight = 0;
};

double triangle::square() const
{
	return 3 * sqrt(3) * (pow((vertex.x - center.x), 2) + pow((vertex.y + center.y), 2)) / 4;
}

double ellipse::square() const
{
	return 3.141592653589793 * 4 * sqrt(pow(HalfShA.x - center.x, 2) + pow(HalfShA.y - center.y, 2))
		* sqrt(pow(HalfShB.x - center.x, 2) + pow(HalfShB.y - center.y, 2));
}

double triangle::perimeter()
{
	return 9 / (2 * cos(0.523599));
}

double ellipse::perimeter()
{
	return 2 * (this->square() + pow(2 * sqrt(pow(HalfShA.x - center.x, 2) + pow(HalfShA.y - center.y, 2))
		- 2 * sqrt(pow(HalfShB.x - center.x, 2) + pow(HalfShB.y - center.y, 2)), 2)) / (2 * sqrt(pow(HalfShA.x - center.x, 2) + pow(HalfShA.y - center.y, 2))
			+ 2 * sqrt(pow(HalfShB.x - center.x, 2) + pow(HalfShB.y - center.y, 2)));
}

double triangle::mass() const
{
	return this->weight;
}

double ellipse::mass() const
{
	return this->weight;
}

CVector2D triangle::position()
{
	return this->center;
}

CVector2D ellipse::position()
{
	return this->center;
}

bool triangle::operator== (const IPhysObject& ob) const
{
	return this->mass() == ob.mass();
}

bool triangle::operator< (const IPhysObject& ob) const
{
	return this->mass() < ob.mass();
}

bool ellipse::operator== (const IPhysObject& ob) const
{
	return this->mass() == ob.mass();
}

bool ellipse::operator< (const IPhysObject& ob) const
{
	return this->mass() < ob.mass();
}

void triangle::draw()
{
	std::cout << "Center of triangle: " << center.x << ' ' << center.y << std::endl
		<< "First vertex: " << vertex.x << ' ' << vertex.y << std::endl
		<< "Mass of triangle: " << mass() << std::endl;
}

void ellipse::draw()
{
	std::cout << "Center of ellipse: " << center.x << ' ' << center.y << std::endl
		<< "Coordinates of extreme point of the big half shaft: " << HalfShA.x << ' ' << HalfShA.y << std::endl
		<< "Coordinates of extreme point of the small half shaft: " << HalfShB.x << ' ' << HalfShB.y << std::endl
		<< "Mass of ellipse: " << mass() << std::endl;
}

void triangle::initFromDialog()
{
	std::cout << "Enter coordinates of center: ";
	std::cin >> center.x >> center.y;
	std::cout << "Enter coordinates of one vertex: ";
	std::cin >> vertex.x >> vertex.y;
	std::cout << "Enter mass: ";
	std::cin >> weight;
}

void ellipse::initFromDialog()
{
	std::cout << "Enter coordinates of center: ";
	std::cin >> center.x >> center.y;
	std::cout << "Enter coordinates of one extreme point of the big half shaft: ";
	std::cin >> HalfShA.x >> HalfShA.y;
	std::cout << "Enter coordinates of one extreme point of the small half shaft: ";
	std::cin >> HalfShB.x >> HalfShB.y;
	std::cout << "Enter mass: ";
	std::cin >> weight;
}

const char* triangle::classname()
{
	return "triangle";
}

const char* ellipse::classname()
{
	return "triangle";
}

unsigned int triangle::size()
{
	return sizeof(triangle);
}

unsigned int ellipse::size()
{
	return sizeof(triangle);
}