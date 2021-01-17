#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H
#include <bits/stdc++.h>

class Point;
class Ball;
class Line;

class Point {
public:
	double x, y;

	Point() = default;
	Point(double x, double y) : x(x), y(y) {}

	Point& operator=(const Point& other) = default;
	Point& operator=(const Ball& other);
	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	void print() const;
	bool on_line(const Line& line) const;
	void mirror(const Line& line);
};

class Ball : public Point {
public:
	double d;

	Ball() = default;
	Ball(double x, double y, double d) : Point(x, y), d(d) {};

	Ball& operator=(const Ball& other) = default;
	Ball& operator=(const Point& other);
};

class Line {
public:
	Point p, q;

	Line() = default;
	Line(const Point& p1, const Point& p2) : p(p1), q(p2) {}
	Line(const Ball& p1, const Point& p2) : p(p1), q(p2) {}

	Line& operator=(const Line& other) = default;
	double length() const;
	Point intersection(const Line &line);
};


#endif
