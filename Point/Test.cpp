//
// Created by ian on 3/28/20.
//
#pragma once


#include "Point.h"
#include <iostream>
#include <iomanip>

void printLineTest(Line tester){
    std::cout << tester << std::fixed << std::setprecision(5) <<
            "\nQuandrant: " << tester.getQuadrant() <<
            "\nSin: " << tester.getSin() <<
            "\nCos: " << tester.getCos() <<
            "\ngetBottom: " << tester.getBottom() <<
            "\ngetRight: " << tester.getRight() <<
            "\ngetTop: " << tester.getTop() <<
            "\ngetLeft: " << tester.getLeft() <<
            "\n\n";
}

int main(){
    Point Origin(0,0);
    {
        Point First(1, 1), Second(-1, 1), Third(-1, -1), Fourth(1, -1);

        std::cout << "First Quadrant: \n";
        printLineTest(Line(Origin, First));

        std::cout << "Second Quadrant: \n";
        printLineTest(Line(Origin, Second));

        std::cout << "Third Quadrant: \n";
        printLineTest(Line(Origin, Third));

        std::cout << "Fourth Quadrant: \n";
        printLineTest(Line(Origin, Fourth));
    }
    {
        Point First(3, 4), Second(-3, 4), Third(-3, -4), Fourth(3, -4);
        std::cout << "\n\n3,4 Section";

        std::cout << "First Quadrant: \n";
        printLineTest(Line(Origin, First));

        std::cout << "Second Quadrant: \n";
        printLineTest(Line(Origin, Second));

        std::cout << "Third Quadrant: \n";
        printLineTest(Line(Origin, Third));

        std::cout << "Fourth Quadrant: \n";
        printLineTest(Line(Origin, Fourth));
    }
    {
        Point First(1,0), Second(0,1), Third(-1, 0), Fourth(0,-1);
        std::cout << "\n\nQuadrant Test";

        std::cout << "First Quadrant: \n";
        printLineTest(Line(Origin, First));

        std::cout << "Second Quadrant: \n";
        printLineTest(Line(Origin, Second));

        std::cout << "Third Quadrant: \n";
        printLineTest(Line(Origin, Third));

        std::cout << "Fourth Quadrant: \n";
        printLineTest(Line(Origin, Fourth));
    }

}