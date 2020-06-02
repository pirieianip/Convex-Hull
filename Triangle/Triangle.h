//
// Created by ian on 3/29/20.
//

#ifndef CONVEX_HULL_TRIANGLE_H
#define CONVEX_HULL_TRIANGLE_H
#pragma once

#define PI 3.1415926535f

#include "../Point/Point.h"

float degreesToRadians(float input);

float radiansToDegrees(float input);

class Triangle {
    Line A, B, C;
    Point a, b, c;
    float aTheta, bTheta, cTheta, aHeight, bHeight, cHeight;

    Point Centroid;

    static float lawOfCosineAngle(const Point& c, const Point& a, const Point& b);
    static float LawOfSine(float Side, float Angle);

    static bool check_Side(const Line& l, const Point& p,const Point& Check);
    static Point create_Centroid(const Point& a, const Point& b, const Point& c);

    static float getHeight(const Line& a, const Line& b, const Line& c);
    static float HeronsFormula( const Line& a,const Line& B, const Line& C);
public:
    Triangle():Triangle(Point(),Point(),Point()){};

    Triangle(const Point& APoint,const Point& BPoint, const Point& CPoint);;

    Triangle(const Line& line, const Point& C);

    [[nodiscard]] Point getCentroid() const {return Centroid;};

    Triangle(const Triangle&) = default;

    bool isInside(const Point& Check);

    float circumference(){return( Line(a,b).getMag() + Line(b,c).getMag() + Line(c,a).getMag());};

    [[nodiscard]] Line getSideA() const{ return A;};

    [[nodiscard]] Line getSideB() const{ return B;};

    [[nodiscard]] Line getSideC() const{ return C;};

    [[nodiscard]] Point getPointA() const{ return a;};

    [[nodiscard]] Point getPointB() const{ return b;};

    [[nodiscard]] Point getPointC() const{ return c;};

    [[nodiscard]] float getATheta() const{ return aTheta;};

    [[nodiscard]] float getBTheta() const{ return bTheta;};

    [[nodiscard]] float getCTheta() const{ return cTheta;};

    [[nodiscard]] float getAHeight() const { return aHeight;}

    [[nodiscard]] float getBHeight() const { return bHeight;}

    [[nodiscard]] float getCHeight() const { return cHeight;}

};



#endif //CONVEX_HULL_TRIANGLE_H

