#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(){};
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX(){return x;}
    int getY(){return y;}
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
};

class Rectangle
{
    Point p1;
    Point p2;
public:
	Rectangle(){};
	Rectangle(Point p1, Point p2)
	{
		this->p1 = p1;
		this->p2 = p2;
	}

    int parameter()
    {
		int p = 2*abs(p1.getX() - p2.getX()) + 2*abs(p1.getY() - p2.getY());
		return p;
    }
    int face()
    {
    	int f = abs((p1.getX() - p2.getX()) * (p1.getY() - p2.getY()));
    	return f;
    }
};

double distance(Point p1, Point p2)
{
    return sqrt((p2.getX()-p1.getX())*(p2.getX()-p1.getX()) + (p2.getY()-p1.getY())*(p2.getY()-p1.getY()));
}

int main()
{
    Point p1(1,0);
    Point p2(3,2);
	Rectangle r(p1,p2);
    cout<<r.face()<<endl;
    cout<<r.parameter()<<endl;
}
