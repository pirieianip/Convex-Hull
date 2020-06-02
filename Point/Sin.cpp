//
// Created by ian on 3/6/20.
//
#pragma once

#include "Point.h"
#include <cmath>

float sinLine(const Line& L){
    return sinPoint(L.getP2() - L.getP1());
}

float sinPoint(const Point& L){
    return std::asinhf( L.getY() / L.getHypot());
}

float cosLine(const Line& L){
    return cosPoint(L.getP2()-L.getP1());
}

float cosPoint(const Point& L){
    return std::acoshf(L.getX()/ L.getHypot());
}