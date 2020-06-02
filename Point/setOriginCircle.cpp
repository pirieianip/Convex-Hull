//
// Created by ian on 3/28/20.
//
#pragma once

#include "Point.h"
#include <cmath>

#define PI 3.14159265f

float normalize(float degree){
    if(degree < 0.0f)
        degree += 360;
    if(degree >= 360.0f)
        degree -= 360;

    return degree;
}

void Line::SetOriginCircle() {
    BottomC = std::asin(sin) * 180.0f / PI;
    RightC = std::acos(cos) * 180.0f / PI;
    TopC = std::asin(sin) * 180.0f / PI + 180;
    LeftC = std::acos(cos) * 180.0f / PI + 180;


    BottomC = normalize(BottomC);
    RightC = normalize(RightC);
    TopC = normalize(TopC);
    LeftC = normalize(LeftC);

//    switch(whichQuadrant){
//        case Quadrant::First:
//            RightC += 90;
//            TopC += 180;
//            LeftC += 270;
//            break;
//        case Quadrant::Second:
//            BottomC += 90;
//            RightC += 180;
//            TopC -= 90;
//            break;
//        case Quadrant::Third:
//            BottomC += 180;
//            RightC += 270;
//            TopC;
//            LeftC -= 90;
//            break;
//        case Quadrant::Fourth:
//            BottomC = 4 + sin;
//            RightC = cos;
//            TopC = 2 + sin;
//            LeftC = 2 + cos;
//            break;
//    }

}








