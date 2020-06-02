//
// Created by ian on 3/27/20.
//

#include <iostream>
#include "Jarvis.h"
#include "../Helpers/Helper.h"

int main(){
    std::srand(time(0));
//    {
//        std::vector<Point> ten;
//        ten.emplace_back(Point(132, 188));
//        ten.emplace_back(Point(324, 43));
//        ten.emplace_back(Point(128, 113));
//        ten.emplace_back(Point(145, 77));
//        ten.emplace_back(Point(110, 178));
//        ten.emplace_back(Point(121, 183));
//        ten.emplace_back(Point(238, 396));
//        ten.emplace_back(Point(41, 77));
//
//        Jarvis Grahh(ten);
//
//        auto i = Grahh.Convex_Hull();
//
//        std::vector<Point> P;
//
//        for (auto iter: i) {
//            std::cout << iter << "\n";
//        }
//    }
//    {
//        std::vector<Point> ten;
//
//        ten.emplace_back(Point(1,1));
//        ten.emplace_back(Point(3,1));
//        ten.emplace_back(Point(2,2));
//        ten.emplace_back(Point(1,3));
//        ten.emplace_back(Point(3,3));
//
//
//        Jarvis Grahh(ten);
//
//        auto i = Grahh.Convex_Hull();
//
//
//        std::vector<Point> P;
//
//        for (auto iter: i) {
//            std::cout << iter << "\n";
//        }
//
////        output(i,"../hull.txt");
////        output(ten, "../test.txt");
//
//
//    }
    {
        std::srand(time(nullptr));
        std::vector<Point> ten;

        int size = 1000000;

        while(ten.size() < size){
            ten.emplace_back(rand()%(size/100), rand()%(size/100));
        }

        auto start = std::chrono::steady_clock::now();
        Jarvis Grahh(ten);
        auto end = std::chrono::steady_clock::now();


//        std::vector<Point> P;
//        for (auto iter: i) {
//            std::cout << iter << "\n";
//        }

        std::cout << "size of array: " << ten.size() << "\n"
                  << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\n";

//        output(i,"../hull.txt");
//        output(ten, "../test.txt");
    }
//    {
//        std::vector<Point> ten;
//        Point One(5,0), Two(1,1), Three(9,1), Four(10, 3),Five(0,3), Six(9,4),
//              Seven(1,4), Eight(5,5), Nine(5,3), Ten(7,3), Eleven(3,3);
//
//        ten.emplace_back(One);
//        ten.emplace_back(Two);
//        ten.emplace_back(Three);
//        ten.emplace_back(Four);
//        ten.emplace_back(Five);
//        ten.emplace_back(Six);
//        ten.emplace_back(Seven);
//        ten.emplace_back(Eight);
//        ten.emplace_back(Nine);
//        ten.emplace_back(Ten);
//        ten.emplace_back(Eleven);
//
//        Jarvis Jarv(ten);
//
//        auto i = Jarv.Convex_Hull();
//
//        for (auto iter: i) {
//            std::cout << iter << "\n";
//        }
//
//    }
}