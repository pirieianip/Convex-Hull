//
// Created by ian on 3/30/20.
//

#include "Triangle.h"
#pragma once

Point Triangle::create_Centroid(const Point& a, const Point& b, const Point& c) {
//    float x = (a.getX() + b.getX() + c.getX()) / 3,
//          y = (a.getY() + b.getY() + c.getY()) / 3;
//    return Point(x,y);
    return Point((a.getX() + b.getX() + c.getX()) / 3.0f, (a.getY() + b.getY() + c.getY()) / 3.0f);
}