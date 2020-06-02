//
// Created by ian on 3/2/20.
//

#ifndef CONVEX_HULL_GRAHAM_H
#define CONVEX_HULL_GRAHAM_H



#include <list>
#include "../Jarvis/Jarvis.h"

class Graham : public Hull {
    std::vector<Point> Data;


    static int compare(const void * a, const void * b);

    Point Bottom, Top, Right, Left;

    bool found_Top, found_Right, found_Left;

    static int pop(const Point& NextToTop, const Point& Top, const Point& Next);

    std::vector<Point> Sort(const std::vector<Point>& Input);

    std::vector<Point> Push_Pop(const std::vector<Point>& input);

    static std::vector<Line> Future_Lines(const std::vector<Point>& Points, const Point& Init){
        std::vector<Line> ret(Points.size());
        for(int i = 0; i < Points.size();++i){
            ret[i] = Line(Init, Points[i]);
        }
        return ret;
    }

public:
    virtual ~Graham();;
public:
    explicit Graham(const std::vector<Point>& Input);



    std::vector<Point> Convex_Hull() override;
};



#endif //CONVEX_HULL_GRAHAM_H
