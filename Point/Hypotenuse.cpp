//
// Created by ian on 3/6/20.
//
#pragma once

#include "Point.h"
#include <cmath>

float hypotenusePoint(float x, float y){
    return std::sqrt((x*x) + (y*y));
}