//
// Created by ian on 3/8/20.
//

#ifndef CONVEX_HULL_FUTURE2_H
#define CONVEX_HULL_FUTURE2_H

#include <vector>
#include <iostream>
#include "Jarvis.h"

std::vector<Line> Future(const std::vector<Line>& Points, const Point& Init, const Point& Deletor, const Point& topDeletor){
    Line Deletion(Init, Deletor), topDeletion(Init, topDeletor);
    if(Deletor != topDeletor) {
        std::vector<Line> ret(Points.size());
        for (int i = 0; i < Points.size(); ++i) {
            ret[i] = Line(Init, Points[i].getP2());
        }
        return ret;
    } else {
        std::vector<Line> ret;
        for(int i = 0; i < Points.size(); ++i){
            Line Check(Init, Points[i].getP2());
            std::cout << "Check:      " << Check
                      << "\nDeletion:   " << Deletion
                      << "\ntopDeletor: " << topDeletion
                      << "\n" << Check.getBottom() << " > " << Deletion.getBottom()
                      << "\n" << Check.getBottom() << " < " << topDeletion.getBottom()
                      << "\n";

            if (!(Check.getBottom() >= Deletion.getBottom() && Check.getBottom() <= topDeletion.getBottom())){
                ret.emplace_back(Check);
                std::cout << "Kept\n";
            } else {
                std::cout << "Deleted\n";
            }
        }
        return ret;
    }
};


#endif //CONVEX_HULL_FUTURE2_H
