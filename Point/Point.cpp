//
// Created by ian on 3/2/20.
//
#pragma once

#include "Point.h"

bool Point::operator==(const Point &rhs) const {
    return int(x) == int(rhs.x) &&
           int(y) == int(rhs.y);
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

bool Point::operator<(const Point &p2) const {
    if(y < p2.y)
        return true;
    else if(y == p2.y){
        return x < p2.x;
    } else
        return false;
}

bool Point::operator>(const Point &p2) const {
    if(y > p2.y)
        return true;
    else if(y == p2.y){
        return x > p2.x;
    } else
        return false;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os  << point.x << "\t" << point.y;
    return os;
}

Point Point::operator-(const Point &P) const {
    return Point(x-P.x,y-P.y);
}

bool Line::operator<=(const Point &P) const {
    return P.getY() <= getSlope() * P.getX() + getYIntercept();
}

bool Line::operator>=(const Point &P) const {
    return P.getY() >= getSlope() * P.getX() + getYIntercept();
}

bool Line::operator==(const Point &P) const {
    return P.getY() == getSlope() * P.getX() + getYIntercept();
}