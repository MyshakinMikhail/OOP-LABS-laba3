#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(double w = 0, double h = 0);

    Point center() const override;
    double area() const override;
    Figure *clone() const override;
    bool operator==(const Figure &other) const override;

protected:
    void print(std::ostream &os) const override;
    void read(std::istream &is) override;

private:
    double width, height;
};
