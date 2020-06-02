//
// Created by ian on 3/28/20.
//

#include <iostream>
#include "Jarvis.h"
void Jarvis::outputTest(const std::vector<Line>& Lines) {
    for(auto i :Lines) {
        switch (dir) {
            case left:
                std::cout << i << "\t\tQuadrant Value Check: " <<  i.getLeft() << "\n";
                break;
            case right:
                std::cout << i << "\t\tQuadrant Value Check: "  << i.getRight() << "\n";
                break;
            case down:
                std::cout << i << "\t\tQuadrant Value Check: " << i.getBottom() << "\n";
                break;
            case top:
                std::cout << i << "\t\tQuadrant Value Check: " << i.getTop() << "\n";
                break;
        }
    }
}

void Jarvis::outputTest(const std::vector<Point> &Points) {
    std::cout << "Points so far: \n";

    for(auto i :Points) {
        std::cout << i << "\n";
    }
}