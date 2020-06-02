//
// Created by ian on 3/27/20.
//

//
// Created by ian on 3/27/20.
//

#include <iostream>
#include "Graham.h"
#include "../Helpers/Helper.h"

int main(){
    std::vector<Point> ten;
    ten.emplace_back(Point(132,188));
    ten.emplace_back(Point(324,43));
    ten.emplace_back(Point(128,113));
    ten.emplace_back(Point(145,77));
    ten.emplace_back(Point(110,178));
    ten.emplace_back(Point(121,183));
    ten.emplace_back(Point(238,396));
    ten.emplace_back(Point(41,77));

    Graham Grahh(ten);

    auto i = Grahh.Convex_Hull();

    std::vector<Point> P;

    for(auto iter: i){
        std::cout << iter << "\n";
    }

    output(i,"../GUI4ConvexHall/hull.txt");
    output(ten, "../GUI4ConvexHall/test.txt");
}