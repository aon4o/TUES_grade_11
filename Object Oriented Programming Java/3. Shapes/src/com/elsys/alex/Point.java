package com.elsys.alex;

import static java.lang.Math.*;

public class Point {
    public double x;
    public double y;

    public Point() {}
    public Point(double x, double y)
    {
        this.x = x;
        this.y = y;
    }

    public double distance(Point other)
    {
        return abs(sqrt((this.x - other.x) * (this.x - other.x) + (this.y - other.y) * (this.y - other.y)));
    }
}
