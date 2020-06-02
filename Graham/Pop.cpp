//
// Created by ian on 3/7/20.
//

#include "Graham.h"

int Graham::pop(const Point& NextToTop, const Point& Top, const Point& Next) {
    int val = (Top.getY() - NextToTop.getY()) * (Next.getX() - Top.getX()) -
              (Top.getX() - NextToTop.getX()) * (Next.getY() - Top.getY());

    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
}
