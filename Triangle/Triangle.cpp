//
// Created by ian on 3/29/20.
//
#pragma once

#include <iostream>
#include "Triangle.h"
#define PI 3.1415926535f

Triangle::Triangle(const Point& APoint, const Point& BPoint,const Point& CPoint):
        a(APoint), b(BPoint), c(CPoint),
        A(CPoint, BPoint),
        B(APoint, CPoint),
        C(APoint, BPoint),
        aTheta(lawOfCosineAngle(APoint, BPoint, CPoint)),
        bTheta(lawOfCosineAngle(BPoint, CPoint, APoint)),
        cTheta(lawOfCosineAngle(CPoint, APoint, BPoint)),
        Centroid(create_Centroid(APoint,BPoint,CPoint))
{
    aHeight = std::abs(getHeight(A,B,C));
    bHeight = std::abs(getHeight(B,A,C));
    cHeight = std::abs(getHeight(C,A,B));
}

Triangle::Triangle(const Line& line,const Point& C): Triangle(line.getLeftMostPoint(),line.getRightMostPoint(), C){
}
