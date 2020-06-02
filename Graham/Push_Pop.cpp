//
// Created by ian on 3/5/20.
//

#include "Graham.h"

std::vector<Point> Graham::Push_Pop(const std::vector<Point> &input) {
//    std::cout << "input_Push_Pop: " << input.size() << "\n";
    std::vector<Point> ret;
    ret.push_back(input[0]);
    ret.push_back(input[1]);
    ret.push_back(input[2]);


//    std::cout << "Ret Size after 0 & 1: " << ret.size() << "\n";


    for(int i = 3; i < input.size(); ++i){
        while(pop(ret[ret.size()-2], ret[ret.size()-1], input[i]) != 2){
            ret.pop_back();
        }
        ret.push_back(input[i]);
    }
    ret.pop_back();
    return ret;
}
