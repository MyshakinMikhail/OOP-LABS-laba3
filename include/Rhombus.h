#pragma once
#include "Figure.h"

class Rhombus : public Figure
{
public:
	Rhombus(double d1 = 0, double d2 = 0);

	Point center() const override;
	double area() const override;
	Figure *clone() const override;
	bool operator==(const Figure &other) const override;

protected:
	void print(std::ostream &os) const override;
	void read(std::istream &is) override;

private:
	double diag1, diag2;
};
