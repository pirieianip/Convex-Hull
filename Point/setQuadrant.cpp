//
// Created by ian on 3/28/20.
//
#pragma once

#include "Point.h"

Line::Quadrant Line::setQuadrant(const Point& Origin) {
    if(Origin.getX() > 0 && Origin.getY() >= 0.0f)
        return First;
    if(Origin.getX() <= 0 && Origin.getY() > 0)
        return Second;
    if(Origin.getX() < 0 && Origin.getY() <= 0)
        return Third;
    else
        return Fourth;
}