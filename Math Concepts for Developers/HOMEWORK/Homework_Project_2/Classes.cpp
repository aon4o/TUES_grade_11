#include "Classes.h"
#include <iostream>
#include <cmath>

using namespace std;

Point &Point::operator=(const Ball &other) {
	x = other.x;
	y = other.y;
	return *this;
}

bool Point::operator==(const Point &other) const {
	if(this->x == other.x and this->y == other.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Point::operator!=(const Point &other) const {
	if(this->x != other.x or this->y != other.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Point::print() const {
	cout << "x = " << this->x << "; y = " << this->y << ";" << endl;
}

bool Point::on_line(const Line& line) const {
	if(x <= max(line.p.x, line.q.x) && x >= min(line.p.x, line.q.x) &&
	   (y <= max(line.p.y, line.q.y) && y >= min(line.p.y, line.q.y)))
		return true;

	return false;
}

void Point::mirror(const Line& line) {
	double a = ((line.q.y - line.p.y) / line.length());
	double b = (-(line.q.x - line.p.x) / line.length());
	double c = (((-line.q.y + line.p.y) * line.p.x + (line.q.x - line.p.x) * line.p.y) / line.length());

	double temp = -2 * (a * x + b * y + c) / (a * a + b * b);
	x = temp * a + x;
	y = temp * b + y;
}

Ball& Ball::operator=(const Point &other) {
	x = other.x;
	y = other.y;
	return *this;
}

double Line::length() const {
	return sqrt((q.x - p.x)*(q.x - p.x) + (q.y - p.y)*(q.y - p.y));
}

Point Line::intersection(const Line& line)
{
	// Line AB represented as a1x + b1y = c1
	double a1 = q.y - p.y;
	double b1 = p.x - q.x;
	double c1 = a1*(p.x) + b1*(p.y);

	// Line CD represented as a2x + b2y = c2
	double a2 = line.p.y - line.p.y;
	double b2 = line.p.x - line.q.x;
	double c2 = a2*(line.p.x)+ b2*(line.p.y);

	double determinant = a1*b2 - a2*b1;

	// IF THE LINES ARE PARALLEL
	if (determinant == 0)
	{
		return Point(DBL_MAX, DBL_MAX);
	}

	Point intersection((b2*c1 - b1*c2)/determinant, (a1*c2 - a2*c1)/determinant);

	//	IF THE INTERSECTION POINT IS NOT ON THE EDGE
	if (intersection.on_line(line) and intersection.on_line(*this))
	{
		return intersection;
	}

	return Point(DBL_MAX, DBL_MAX);
}
