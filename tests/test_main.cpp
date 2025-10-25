#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include "../include/FigureArray.h"
#include "gtest/gtest.h"

// ------------------ Rectangle Tests ------------------
TEST(RectangleTest, AreaAndCenter)
{
	Rectangle r(4, 5);
	EXPECT_DOUBLE_EQ(r.area(), 20);
	Point c = r.center();
	EXPECT_DOUBLE_EQ(c.x, 2);
	EXPECT_DOUBLE_EQ(c.y, 2.5);
	EXPECT_DOUBLE_EQ(c.z, 0);
}

TEST(RectangleTest, EqualityAndClone)
{
	Rectangle r1(3, 6);
	Rectangle r2(3, 6);
	Rectangle r3(2, 5);
	EXPECT_TRUE(r1 == r2);
	EXPECT_FALSE(r1 == r3);

	Figure *cloneR = r1.clone();
	EXPECT_TRUE(*cloneR == r1);
	delete cloneR;
}

// ------------------ Trapezoid Tests ------------------
TEST(TrapezoidTest, AreaAndCenter)
{
	Trapezoid t(3, 5, 4);
	EXPECT_DOUBLE_EQ(t.area(), 16);
	Point c = t.center();
	EXPECT_DOUBLE_EQ(c.x, 2);
	EXPECT_DOUBLE_EQ(c.y, 2);
	EXPECT_DOUBLE_EQ(c.z, 0);
}

TEST(TrapezoidTest, EqualityAndClone)
{
	Trapezoid t1(3, 5, 4);
	Trapezoid t2(3, 5, 4);
	Trapezoid t3(2, 5, 4);
	EXPECT_TRUE(t1 == t2);
	EXPECT_FALSE(t1 == t3);

	Figure *cloneT = t1.clone();
	EXPECT_TRUE(*cloneT == t1);
	delete cloneT;
}

// ------------------ Rhombus Tests ------------------
TEST(RhombusTest, AreaAndCenter)
{
	Rhombus r(6, 8);
	EXPECT_DOUBLE_EQ(r.area(), 24);
	Point c = r.center();
	EXPECT_DOUBLE_EQ(c.x, 3);
	EXPECT_DOUBLE_EQ(c.y, 4);
	EXPECT_DOUBLE_EQ(c.z, 0);
}

TEST(RhombusTest, EqualityAndClone)
{
	Rhombus r1(6, 8);
	Rhombus r2(6, 8);
	Rhombus r3(5, 8);
	EXPECT_TRUE(r1 == r2);
	EXPECT_FALSE(r1 == r3);

	Figure *cloneR = r1.clone();
	EXPECT_TRUE(*cloneR == r1);
	delete cloneR;
}

// ------------------ FigureArray Tests ------------------
TEST(FigureArrayTest, AddRemoveAndTotalArea)
{
	FigureArray arr;
	Rectangle r(2, 3);
	Trapezoid t(3, 5, 4);
	Rhombus rh(6, 8);

	arr.add(&r);
	arr.add(&t);
	arr.add(&rh);

	EXPECT_DOUBLE_EQ(arr.totalArea(), 6 + 16 + 24);

	arr.remove(1); // удаляем Trapezoid
	EXPECT_DOUBLE_EQ(arr.totalArea(), 6 + 24);

	arr.clear();
	EXPECT_DOUBLE_EQ(arr.totalArea(), 0);
}