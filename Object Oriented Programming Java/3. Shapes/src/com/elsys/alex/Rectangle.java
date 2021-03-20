package com.elsys.alex;

import java.util.ArrayList;
import java.util.List;

public class Rectangle extends Shape {
    double longSide;
    double shortSide;

    public Rectangle(Point centre, double sideA, double sideB)
    {
        if (sideA > sideB) {
            longSide = sideA;
            shortSide = sideB;
        } else {
            longSide = sideB;
            shortSide = sideA;
        }
    }

    @Override
    public boolean checkCollision(Shape other) { //todo
        return false;
    }

    @Override
    public List<Point> getPoints()
    {
        List<Point> points = new ArrayList<>();
        points.add(0, new Point(centre.x - longSide/2, centre.y + shortSide/2));
        points.add(1, new Point(centre.x + longSide/2, centre.y + shortSide/2));
        points.add(2, new Point(centre.x - longSide/2, centre.y - shortSide/2));
        points.add(3, new Point(centre.x + longSide/2, centre.y - shortSide/2));
        return points;
    }
}
