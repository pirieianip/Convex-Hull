//
// Created by ian on 3/2/20.
//

#include "Point.h"
#pragma once

void Line::create_y_intercept() {
    y_intercept = p1.getY() - (slope * p1.getX());
}



