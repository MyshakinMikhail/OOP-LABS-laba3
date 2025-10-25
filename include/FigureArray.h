#pragma once
#include <vector>
#include "Figure.h"

class FigureArray
{
public:
	~FigureArray();

	void add(Figure *f);
	void remove(size_t index);
	void printAll() const;
	double totalArea() const;
	void clear();

private:
	std::vector<Figure *> figures;
};
