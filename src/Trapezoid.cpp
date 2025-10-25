#include "Trapezoid.h"
#include <iostream>

Trapezoid::Trapezoid(double t, double b, double h) : top(t), bottom(b), height(h) {}

Point Trapezoid::center() const
{
	return Point((top + bottom) / 4, height / 2, 0);
}

double Trapezoid::area() const
{
	return (top + bottom) * height / 2;
}

Figure *Trapezoid::clone() const
{
	return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure &other) const
{
	const Trapezoid *o = dynamic_cast<const Trapezoid *>(&other);
	return o && o->top == top && o->bottom == bottom && o->height == height;
}

void Trapezoid::print(std::ostream &os) const
{
	double diff = (bottom - top) / 2;
	os << "Trapezoid vertices: ";
	os << "(" << diff << ",0,0), ";
	os << "(" << diff + top << ",0,0), ";
	os << "(" << bottom << "," << height << ",0), ";
	os << "(0," << height << ",0)";
}

void Trapezoid::read(std::istream &is)
{
	is >> top >> bottom >> height;
}
