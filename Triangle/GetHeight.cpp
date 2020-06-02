//
// Created by ian on 3/29/20.
//
#pragma once

#include "Triangle.h"
#include <cmath>

float Triangle::getHeight(const Line& a, const Line& b, const Line& c) {
    return 2 * HeronsFormula(a,b,c) / a.getMag();
}

float Triangle::HeronsFormula(const Line &a, const Line &b, const Line &c) {
    float s = (a.getMag() + b.getMag() + c.getMag())/2;

    return std::sqrt(s * (s - a.getMag()) * (s - b.getMag()) * (s - c.getMag()));
}