//
// Created by ian on 3/29/20.
//
#pragma once

#include "Triangle.h"

bool Triangle::isInside(const Point& Check) {
    return(check_Side(C, c, Check) &&
       check_Side(A, a, Check) &&
       check_Side(B, b, Check));
}

bool Triangle::check_Side(const Line& l, const Point& p, const Point& Check) {
    return((l <= p && l <= Check) || (l >= p && l >= Check));
}




