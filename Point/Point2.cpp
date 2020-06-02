//
// Created by ian on 3/8/20.
//
#pragma once

#include "Point.h"
#include <cmath>

Point::Point(float X, float Y): x(X), y(Y), hypotenuse(std::hypot(X,Y)){

}

Point::Point(int X, int Y) : x(static_cast<float>(X)), y(static_cast<float>(Y)), hypotenuse(std::hypot(x,y)) {

}