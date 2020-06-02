//
// Created by ian on 3/2/20.
//

#ifndef CONVEX_HULL_JARVIS_H
#define CONVEX_HULL_JARVIS_H

#include "../Quick/Quick_Hull.h"


class Jarvis {

    std::vector<Point> Data;

    enum Direct{
        left,
        right,
        down,
        top,
    } dir;
public:
    virtual ~Jarvis();

private:

    Point Bottom;

    void Jarvis_March(const std::vector<Point>& Input);

    void outputTest(const std::vector<Line>& Lines);
    void outputTest(const std::vector<Point>& Lines);

public:
    explicit Jarvis(const std::vector<Point>& Input);


    std::vector<Point> Convex_Hull() {return Data;};

    friend std::ostream& operator<<(std::ostream& os, Direct dir) {
        switch(dir){
            case Direct::left:
                os << "Left";
                break;
            case Direct::right:
                os << "Right";
                break;
            case Direct::down:
                os << "Bottom";
                break;
            case Direct::top:
                os << "Top";
                break;
        }
        return os;
    }

};

#endif //CONVEX_HULL_JARVIS_H
