//
// Created by ian on 4/5/20.
//

#include <iostream>
#include "Helper.h"

std::vector<Point> getPoints(std::string file){
    std::vector<Point> ret;
    std::ifstream ins(file);
    float a,b;
    if(ins.is_open()) {
        while (ins >> a >> b && !ins.eof()){
            ret.emplace_back(Point(a,b));
        }
    } else {
        std::cout << "No File Found\n\n";
    }
    return ret;
}
