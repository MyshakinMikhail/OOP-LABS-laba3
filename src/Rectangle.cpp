#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

Point Rectangle::center() const
{
	return Point(width / 2, height / 2, 0);
}

double Rectangle::area() const
{
	return width * height;
}

Figure *Rectangle::clone() const
{
	return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure &other) const
{
	const Rectangle *o = dynamic_cast<const Rectangle *>(&other);
	return o && o->width == width && o->height == height;
}

void Rectangle::print(std::ostream &os) const
{
	os << "Rectangle vertices: ";
	os << "(0,0,0), ";
	os << "(" << width << ",0,0), ";
	os << "(" << width << "," << height << ",0), ";
	os << "(0," << height << ",0)";
}

void Rectangle::read(std::istream &is)
{
	is >> width >> height;
}
