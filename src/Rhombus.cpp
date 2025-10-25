#include "Rhombus.h"
#include <iostream>

Rhombus::Rhombus(double d1, double d2) : diag1(d1), diag2(d2) {}

Point Rhombus::center() const
{
	return Point(diag1 / 2, diag2 / 2, 0);
}

double Rhombus::area() const
{
	return diag1 * diag2 / 2;
}

Figure *Rhombus::clone() const
{
	return new Rhombus(*this);
}

bool Rhombus::operator==(const Figure &other) const
{
	const Rhombus *o = dynamic_cast<const Rhombus *>(&other);
	return o && o->diag1 == diag1 && o->diag2 == diag2;
}

void Rhombus::print(std::ostream &os) const
{
	os << "Rhombus vertices: ";
	os << "(" << diag1 / 2 << ",0,0), ";
	os << "(" << diag1 << "," << diag2 / 2 << ",0), ";
	os << "(" << diag1 / 2 << "," << diag2 << ",0), ";
	os << "(0," << diag2 / 2 << ",0)";
}

void Rhombus::read(std::istream &is)
{
	is >> diag1 >> diag2;
}
