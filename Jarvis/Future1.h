//
// Created by ian on 3/8/20.
//

#ifndef CONVEX_HULL_FUTURE1_H
#define CONVEX_HULL_FUTURE1_H

#include <vector>
#include <algorithm>
#include "Jarvis.h"

std::vector<Line> Future_Lines(const std::vector<Point>& Points, Point Init){
    std::vector<Line> ret(Points.size());
    for(int i = 0; i < Points.size();++i){
        ret[i] = Line(Init, Points[i]);
    }
    return ret;
};

#endif //CONVEX_HULL_FUTURE1_H
