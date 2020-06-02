//
// Created by ian on 3/2/20.
//
#pragma once

#include "Point.h"
#include <cmath>
#include <complex>
#include <iostream>

Line::Line(const Point& P1,const Point& P2):
p1(P1),
p2(P2),
x(P2.getX() - P1.getX()),
y(P2.getY() - P1.getY())
{
    if(P1.getX() < P2.getX())
        Left_Most_Point = true;
    else Left_Most_Point = P1.getX() == P2.getX() && P1.getY() > P2.getY();

    if(y == 0)
        slope = 0;
    else
        slope = y / x;
    create_y_intercept();
    Origin = p2 - p1;
    whichQuadrant = setQuadrant(Origin);
    mag = std::hypot(Origin.getX(),Origin.getY());
    sin = Origin.getY() / mag;
    cos = Origin.getX() / mag;
    tan = std::atan(slope);

    SetOriginCircle();

    auto i = std::polar(mag, tan);
    sinL = i.real();
    cosL = i.imag();

}

Line::Line(float p1x, float p1y, float p2x, float p2y):Line(Point(p1x,p1y),Point(p2x,p2y)){
}

Line::Line(): Line(Point(),Point())
{

}

bool Line::operator<(const Point &P) const {
//    std::cout << P.getY() << " < ( " << P.getX() << " * " << slope << " + " << y_intercept << " )\n";
//    std::cout << P.getY() << " < " << (P.getX() * slope + y_intercept) << "\n";

    return(P.getY() < (P.getX() * slope + y_intercept));
}

bool Line::operator>(const Point &P) const {
//    std::cout << P.getY() << " > ( " << P.getX() << " * " << slope << " + " << y_intercept << " )\n";
//    std::cout << P.getY() << " > " << (P.getX() * slope + y_intercept) << "\n";
    return(P.getY() > (P.getX() * slope + y_intercept));
}

bool Line::operator<(const Line &L) const{
    if(sin > L.sin) {
        return true;
    }
    if(sin == L.sin) {
        return (mag < L.mag);
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Line::Quadrant Quad) {
    switch(Quad){
        case Line::Quadrant::First:
            os << "First";
            break;
        case Line::Quadrant::Second:
            os << "Second";
            break;
        case Line::Quadrant::Third:
            os << "Third";
            break;
        case Line::Quadrant::Fourth:
            os << "Fourth";
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Line &line) {
    os << "p1: " << line.p1
       << " p2: " << line.p2
       << " Origin: " << line.Origin
       << " GetRight: " << line.getRight()
       << " GetLeft: " << line.getLeft()
       << " GetTop: " << line.getTop()
       << " GetBottom: " << line.getBottom()
       << " Quadrant: " << line.getQuadrant()
       << " Magnitude: " << line.getMag();
    return os;
}