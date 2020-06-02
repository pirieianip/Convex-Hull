//
// Created by ian on 3/29/20.
//

#ifndef CONVEX_HULL_QUICK_HULL_H
#define CONVEX_HULL_QUICK_HULL_H
#pragma once

#include <utility>

#include "../Triangle/Triangle.h"
#include "../Convex_Hull.h"
#include "mutexClass.h"

class Quick_Hull : public Hull {
    std::vector<Point> Data;

    struct Quick_Struct{
        std::vector<Point> Points;
        Line initial_line;

        Quick_Struct(std::vector<Point>  p, Line l):
            Points(std::move(p)),
            initial_line(l)
            {};
    };

public:
    virtual ~Quick_Hull();

private:

    static std::vector<Point> Quick(Quick_Struct Data);
    static std::vector<Point> Quick_Full(Quick_Struct Data);
    static std::vector<Point> Quick_Single(std::vector<Point> Points, Line initial_Line);
    static std::vector<Point> Quick_Single_Full(std::vector<Point> Points, Line initial_Line);

public:
    enum thread_test_type{
        singleThread,
        doubleThread,
        multiThread,
        null,
    };

private:
    thread_test_type type;

public:

    explicit Quick_Hull(std::vector<Point> Input);
    explicit Quick_Hull(std::vector<Point> Input, thread_test_type);

    Quick_Hull(Quick_Hull&) = default;

    std::vector<Point> Convex_Hull() override;
};


#endif //CONVEX_HULL_QUICK_HULL_H
