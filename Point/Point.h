//
// Created by ian on 3/2/20.
//

#ifndef CONVEX_HULL_POINT_H
#define CONVEX_HULL_POINT_H
#pragma once

#include "Line.h"
#include <utility>
#include <ostream>


class Point {
    float x, y, hypotenuse;
public:
    Point(int X, int Y);

    Point(float X, float Y);

    Point(const Point& point) = default;

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    Point():x(0.0f),y(0.0f), hypotenuse(0.0){};

    [[nodiscard]] float getX() const { return x;};

    [[nodiscard]] float getY() const { return y;};

    [[nodiscard]] float getHypot() const {return hypotenuse; };

    void setX(float X) { Point::x = X;};

    void setX(const float& X) { Point::x = X;};

    void setY(float Y) { Point::y = Y;};

    void setY(const float& Y) { Point::y = Y;};

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    bool operator<(const Point& x) const;

    bool operator>(const Point& x) const;

    Point operator-(const Point& P) const;
};

class Line {
    Point p1, p2, Origin;
    float y_intercept, slope, sinL, cosL, mag, x ,y, sin, cos, tan, BottomC, RightC, TopC, LeftC;


    /// If true, p1 else p2 is left most point or higher point;
    bool Left_Most_Point;

    void create_slope();
    void create_y_intercept();

public:
    enum Quadrant{
        First = 0,
        Second = 1,
        Third = 2,
        Fourth = 3
    };
private:
    Quadrant whichQuadrant;

    static Quadrant setQuadrant(const Point& Origin);

    void SetOriginCircle();
public:
    Line();

    Line(const Point& P1,const Point& P2);

    Line(float p1x, float p1y, float p2x, float p2y);

    bool operator==(const Line &rhs) const;

    bool operator!=(const Line &rhs) const;

    Line(const Line& L) = default;

    [[nodiscard]] float getX() const{ return x;};

    [[nodiscard]] float getY() const{ return y;};

    [[nodiscard]] float getSlope() const {return slope;};

    [[nodiscard]] float getYIntercept() const{ return y_intercept;};

    [[nodiscard]] Point getP1() const{ return p1;};

    [[nodiscard]] Point getP2() const{ return p2;};

    [[nodiscard]] float getBottom() const {return BottomC;};

    [[nodiscard]] float getRight() const {return RightC;};

    [[nodiscard]] float getTop() const {return TopC;};

    [[nodiscard]] float getLeft() const {return LeftC;};

    [[nodiscard]] float getSin() const {return sin;};

    [[nodiscard]] float getCos() const {return cos;};

    [[nodiscard]] float getMag() const{ return mag;};

    [[nodiscard]] float getPolarSin() const{return sinL;};

    [[nodiscard]] float getPolarCos() const{return cosL;};

    [[nodiscard]] Quadrant getQuadrant() const {return whichQuadrant;};

    float getTan(){return tan;};

    Point getLeftMostPoint() const;

    Point getRightMostPoint() const
    {
        if(Left_Most_Point)
            return p2;
        else
            return p1;
    };

    friend std::ostream &operator<<(std::ostream &os, const Line &line);

    bool operator<(const Point& P) const;
    bool operator<=(const Point& P) const;
    bool operator>(const Point& P) const;
    bool operator>=(const Point& P) const;
    bool operator==(const Point& P) const;

    bool operator<(const Line& L) const;

    friend std::ostream& operator<<(std::ostream &os, const Quadrant Quad);

};


float hypotenusePoint(float x, float y);

float sinLine(const Line& L);
float sinPoint(const Point& L);
float cosLine(const Line& L);
float cosPoint(const Point& L);

#endif //CONVEX_HULL_POINT_H
