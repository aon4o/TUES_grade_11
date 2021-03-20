package com.elsys.alex;

import java.util.List;

abstract class Shape {
    Point centre;

    abstract boolean checkCollision(Shape other);
    abstract List<Point> getPoints();
}
