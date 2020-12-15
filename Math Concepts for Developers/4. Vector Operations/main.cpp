#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector v1 = Vector(Point(0,0), Point(3,5));
	Vector v2 = Vector(Point(3,5), Point(7,3));
	Vector v3 = Vector(Point(0,0), Point(3,2));
	Vector v4 = Vector(Point(0,0), Point(3,3));

	Point arr[3] = {Point(1, 2), Point(3, -1), Point(2, 4)};

	v1.sum(v2);
	v1.diff(v2);
	cout << "Collinear: " << v3.is_collinear(v4) << endl;
	cout << "Length: " << v1.length() << endl;
	cout << "Angle: " << v1.get_angle(v2) << endl;

	cout << "Area: " << area(arr[0], arr[1], arr[2]) << endl;
	cout << "Area: " << area(arr, 3) << endl;

}
