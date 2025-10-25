#include "FigureArray.h"
#include <iostream>

FigureArray::~FigureArray()
{
	clear();
}

void FigureArray::add(Figure *f)
{
	figures.push_back(f->clone());
}

void FigureArray::remove(size_t index)
{
	if (index < figures.size())
	{
		delete figures[index];
		figures.erase(figures.begin() + index);
	}
}

void FigureArray::printAll() const
{
	for (size_t i = 0; i < figures.size(); ++i)
	{
		std::cout << "Figure " << i << ": " << *figures[i]
				  << " Center: " << figures[i]->center()
				  << " Area: " << figures[i]->area() << "\n";
	}
}

double FigureArray::totalArea() const
{
	double sum = 0;
	for (auto f : figures)
		sum += f->area();
	return sum;
}

void FigureArray::clear()
{
	for (auto f : figures)
		delete f;
	figures.clear();
}
