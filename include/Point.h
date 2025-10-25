#pragma once
#include <iostream>

class Point
{
public:
	double x, y, z;

	Point(double x_ = 0, double y_ = 0, double z_ = 0) : x(x_), y(y_), z(z_) {}

	friend std::ostream &operator<<(std::ostream &os, const Point &p)
	{
		os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
		return os;
	}

	friend Point operator+(const Point &a, const Point &b)
	{
		return Point(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	friend Point operator/(const Point &p, double val)
	{
		return Point(p.x / val, p.y / val, p.z / val);
	}
};
