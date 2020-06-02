//
// Created by ian on 3/26/20.
//

#include "Helper.h"

void output(std::vector<Point>& Data, std::string output_file){
    std::ofstream os(output_file);

    for(auto i: Data){
        os << i << "\n";
    }
    os.close();
}

void output(std::vector<Point> Data, std::ostream& out){
    for(auto i: Data){
        out << i << "\n";
    }
}