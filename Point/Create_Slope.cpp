//
// Created by ian on 3/2/20.
//

#include "Point.h"
#pragma once

void Line::create_slope() {
    if(y == 0)
        slope = 0;
    else
        slope = y/x;
}

bool Line::operator==(const Line &rhs) const {
    return y_intercept == rhs.y_intercept &&
           slope == rhs.slope &&
           Left_Most_Point == rhs.Left_Most_Point;
}

bool Line::operator!=(const Line &rhs) const {
    return !(rhs == *this);
}







