//
// Created by ian on 3/29/20.
//
#pragma once

#include "Triangle.h"
#include <cmath>

/**
 * C^2 = A^2 + B^2 - 2ABcos(t)
 * C = Line C
 * A = Line A
 * B = Line B
 * t = Theta
 *
 * C^2 + 2ABcos(a) = A^2 + B^2
 * 2ABcos(a) = A^2 + B^2 - C^2
 * cos(a) = (A^2 + B^2 - C^2) / (2AB)
 */
float Triangle::lawOfCosineAngle(const Point& a,const Point& b,const Point& c) {
    Line A(b,c);
    Line B(a,c);
    Line C(a,b);

    float CP = C.getMag() * C.getMag();
    float BP = B.getMag() * B.getMag();
    float AP = A.getMag() * A.getMag();

    float internal = (BP + CP - AP) /
                     (2 * C.getMag() * B.getMag());

    return(std::acos(internal));
}









