package com.elsys.alex;

import java.util.ArrayList;
import java.util.List;

public class Square extends Shape {
    double side;

    public Square(Point centre, double side)
    {
        this.centre = centre;
        this.side = side;
    }

    @Override
    public boolean checkCollision(Shape other) { //todo
        boolean flag = false;
        List<Point> points = this.getPoints();
        List<Point> pointsOther = other.getPoints();

        return false;
    }

    @Override
    List<Point> getPoints ()
    {
        List<Point> points = new ArrayList<>();
        double radius = side/2;
        points.add(0, new Point(centre.x - radius, centre.y + radius));
        points.add(1, new Point(centre.x + radius, centre.y + radius));
        points.add(2, new Point(centre.x - radius, centre.y - radius));
        points.add(3, new Point(centre.x + radius, centre.y - radius));
        return points;
    }
}
