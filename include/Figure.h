#pragma once
#include <iostream>
#include "Point.h"

class Figure
{
public:
	virtual ~Figure() = default;

	virtual Point center() const = 0;
	virtual double area() const = 0;
	virtual Figure *clone() const = 0;
	virtual bool operator==(const Figure &other) const = 0;
	

	friend std::ostream &operator<<(std::ostream &os, const Figure &f)
	{
		f.print(os);
		return os;
	}

	friend std::istream &operator>>(std::istream &is, Figure &f)
	{
		f.read(is);
		return is;
	}

protected:
	virtual void print(std::ostream &os) const = 0;
	virtual void read(std::istream &is) = 0;
};
