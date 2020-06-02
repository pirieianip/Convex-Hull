//
// Created by ian on 3/29/20.
//

#include <iostream>
#include "Triangle.h"

int main(){
    {
        {
            std::cout << "Testing isInside:\n";

            Point a(1, 1), b(2, 4), c(6, 1), inside(3, 2), outside(5, 5), l(2, 1);
            Triangle Tester(a, b, c);

            std::cout << "Inside(3,2):  ";
            if (Tester.isInside(inside))
                std::cout << "Pass\n";
            else
                std::cout << "Fail\n";

            std::cout << "Outside(5,5): ";
            if (Tester.isInside(outside))
                std::cout << "Fail\n";
            else
                std::cout << "Pass\n";

            std::cout << "onLine(2,1):  ";
            if (Tester.isInside(l))
                std::cout << "Pass\n";
            else
                std::cout << "Fail\n";


            std::cout << "\nTesting Sides: \n";
            std::cout << "Side A Mag: ";
            if (Tester.getSideA().getMag() == 5.0f)
                std::cout << "Pass\n";
            else
                std::cout << "Fail\n";
            std::cout << "Side B Mag: ";
            if (Tester.getSideB().getMag() == 5.0f)
                std::cout << "Pass\n";
            else
                std::cout << "Fail\n";
            std::cout << "Side C Mag: ";
            if (Tester.getSideC().getMag() == Line(a, b).getMag())
                std::cout << "Pass\n";
            else
                std::cout << "Fail\n";

            std::cout << "\nTesting Height:\n";
            std::cout << "Aheight: Suspected: 3.0f Actual: " << Tester.getAHeight();
            std::cout << "\nBheight: Suspected: 3.0f Actual: " << Tester.getBHeight();
            std::cout << "\nCheight: Suspected: 4.74342f Actual: " << Tester.getCHeight();
        }
        {
            Point a(0.0f,0.0f), b(1.0f,1.0f), c(2.0f,0.0f);
            Triangle Tester(a,b,c);
            std::cout << "\n\n\nNew Test Points:"
                      << "\nPoint a: " << a
                      << "\nPoint b: " << b
                      << "\nPoint c: " << c;

            std::cout << "\n\nTesting Angles: ";
            std::cout << "\naTheta: " << radiansToDegrees(Tester.getATheta())
                      << "\nbTheta: " << radiansToDegrees(Tester.getBTheta())
                      << "\ncTheta: " << radiansToDegrees(Tester.getCTheta());

            std::cout << "\n\nTesting Centroid:";
            {
                Point Centroid = Tester.getCentroid();
                std::cout << "\nCentroid: " << Centroid;
            }
        }
    }
}