#include <iostream>
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "FigureArray.h"

int main()
{
	Rectangle r1(3, 6);
	Rectangle r2(3, 6);

	if (r1 == r2)
	{
		std::cout << "=\n";
	}
	else
	{
		std::cout << "!=\n";
	}

	FigureArray array;

	std::cout << "Enter rectangle width and height: ";
	Rectangle r;
	std::cin >> r;
	array.add(&r);

	std::cout << "Enter trapezoid top, bottom, height: ";
	Trapezoid t;
	std::cin >> t;
	array.add(&t);

	std::cout << "Enter rhombus diagonals: ";
	Rhombus rh;
	std::cin >> rh;
	array.add(&rh);

	std::cout << "\nAll figures:\n";
	array.printAll();

	std::cout << "\nTotal area: " << array.totalArea() << "\n";

	std::cout << "\nRemoving first figure...\n";
	array.remove(0);
	array.printAll();

	return 0;
}
