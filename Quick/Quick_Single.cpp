//
// Created by ian on 3/29/20.
//
#include "Quick_Hull.h"

std::vector<Point> Quick_Hull::Quick_Single(std::vector<Point> Points, Line initial_Line) {
    if(Points.size() <= 1)
        return Points;
    std::vector<Point> Left, Right, retRight, retLeft, ret;

    Triangle Largest(initial_Line, Points[0]);
    for(auto i: Points){
        if(std::abs(Triangle(initial_Line, i).getCHeight()) > std::abs(Largest.getCHeight()))
            Largest = Triangle(initial_Line,i);
    }
    Line CenterLine(Largest.getCentroid(), Largest.getPointC());

    for(auto i: Points){
        if(!Largest.isInside(i)){
            if(CenterLine > i)
                Left.emplace_back(i);
            else if(CenterLine < i)
                Right.emplace_back(i);
        }
    }
    ret.emplace_back(Largest.getPointA());
    retLeft = Quick_Single(Left, Largest.getSideB());
    if(!retLeft.empty())
        ret.insert(ret.end(),retLeft.begin(),retLeft.end());
    ret.emplace_back(Largest.getPointC());
    retRight = Quick_Single(Right, Largest.getSideA());
    if(!retRight.empty())
        ret.insert(ret.end(), retRight.begin(), retRight.end());
    return ret;
}