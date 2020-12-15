#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

#define N 50

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
};

class Vector {
	double x, y;
public:
	Vector(double x, double y) : x(x), y(y) {}
	Vector(Point p1, Point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}

	void sum(const Vector& other) const;
	void diff(const Vector& other) const;
	bool is_collinear(const Vector& other) const;
	double length() const;
	double get_angle(const Vector& other) const;
};

double area(const Point& p1, const Point& p2, const Point& p3);
double area(const Point points[50], int size);

#endif //VECTORS_VECTOR_H
