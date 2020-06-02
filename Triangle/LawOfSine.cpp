//
// Created by ian on 3/29/20.
//
#pragma once

#include <cmath>
#include "Triangle.h"

float Triangle::LawOfSine(float Side, float Angle) {
    return Side / std::sin(Angle);
}