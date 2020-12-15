#include "Vector.h"
#include <iostream>
#include <cmath>

using namespace std;

void Vector::sum(const Vector &other) const
{
	cout << "(" << x << ", " << y << ") + (" << other.x << ", " << other.y << ") = ";
	cout << "(" << x + other.x << ", " << y + other.y << ")" << endl;
}

void Vector::diff(const Vector &other) const
{
	cout << "(" << x << ", " << y << ") - (" << other.x << ", " << other.y << ") = ";
	cout << "(" << x - other.x << ", " << y - other.y << ")" << endl;
}

bool Vector::is_collinear(const Vector &other) const {
	return x / y == other.x / other.y;
}

double Vector::length() const {
	return sqrt(x * x + y * y);
}

double Vector::get_angle(const Vector& other) const {
	double dot = x * other.x + y * other.y;
	double angle = (dot / (length() * other.length()));

	return acos(angle);
}

double area(const Point& p1, const Point& p2, const Point& p3)
{
	return 0.5 * abs((p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y));
}

double area(const Point points[50], int size)
{
	double area_result = 0;

	for (int i = 0; i < size - 1; i++)
	{
		area_result += ((points[i].x * points[i + 1].y) - (points[i + 1].x * points[i].y));
	}
	area_result += ((points[size-1].x*points[0].y) - (points[0].x*points[size-1].y));
	area_result = abs(area_result/2);

	return area_result;
}