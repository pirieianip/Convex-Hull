//
// Created by ian on 3/2/20.
//
#pragma once

#include "Point.h"

Point Line::getLeftMostPoint() const {
    if(Left_Most_Point)
        return p1;
    else
        return p2;
}

