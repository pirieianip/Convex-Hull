//
// Created by ian on 3/29/20.
//
#include <vector>
#include "../Point/Point.h"
#include "Quick_Hull.h"
#include <iostream>

void test(const std::vector<Point>& test){
    {
        std::cout << "Single Thread: ";
        auto start = std::chrono::steady_clock::now();
        Quick_Hull Grahh(test, Quick_Hull::thread_test_type::singleThread);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " nanoseconds\n";
    }
    {
        std::cout << "Double Thread: ";
        auto start = std::chrono::steady_clock::now();
        Quick_Hull Grahh(test, Quick_Hull::thread_test_type::doubleThread);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " nanoseconds\n";
    }
    {
        std::cout << "Multi Thread:  ";
        auto start = std::chrono::steady_clock::now();
        Quick_Hull Grahh(test, Quick_Hull::thread_test_type::multiThread);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " nanoseconds\n";
    }
}

int main(){
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
//        Quick_Hull Grahh(ten);
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
//        Quick_Hull Grahh(ten, Quick_Hull::thread_test_type::multiThread);
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
//        srand(time(0));
//        std::vector<Point> ten;
//
//        ten.emplace_back(7,-8);
//        ten.emplace_back(11	,-12);
//        ten.emplace_back(5	,-3);
//        ten.emplace_back(11	,-5);
//        ten.emplace_back(7	,-14);
//        ten.emplace_back(7	,-4);
//        ten.emplace_back(8,	-2);
//        ten.emplace_back(1,	-12);
//        ten.emplace_back(13	,-7);
//        ten.emplace_back(14,	-8);
//        ten.emplace_back(6	,-5);
//        ten.emplace_back(7	,-11);
//        ten.emplace_back(3	,-0);
//        ten.emplace_back(1	,-13);
//        ten.emplace_back(12	,-4);
//
//        Quick_Hull Grahh(ten, Quick_Hull::thread_test_type::multiThread);
//
//        auto i = Grahh.Convex_Hull();
//
//        std::vector<Point> P;
//
//        for (auto iter: i) {
//            std::cout << iter << "\n";
//        }
//        output(i,"../hull.txt");
//        output(ten, "../test.txt");
//    }
//    {
//        std::ifstream is("../test.txt");
//
//        srand(time(0));
//        std::vector<Point> ten;
//        int size = 1000000;
//
//        ten.reserve(size);
//        if(is.is_open()){
//            int a,b;
//            while(!is.eof()){
//                is >> a >> b;
//                ten.emplace_back(a,b);
//            }
//        }
//
//        auto start = std::chrono::steady_clock::now();
//        Quick_Hull Grahh(ten, Quick_Hull::thread_test_type::multiThread);
//        auto end = std::chrono::steady_clock::now();
//
//        auto i = Grahh.Convex_Hull();
//
//        std::vector<Point> P;
//
//        for (auto iter: i) {
//            std::cout << iter << "\n";
//        }
//        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
//                  << " nanoseconds\n";
//        output(i,"../hull.txt");
//        output(ten, "../test.txt");
//    }
    {

        srand(time(nullptr));
        std::vector<Point> ten, hundred, thousand,tenthousand,hundredthousand, million;
        int size = 1000000;
        million.reserve(size);
        while(ten.size() < 10){
            ten.emplace_back(rand(),rand());
        }
        std::cout << "Ten Done\n";
        while(hundred.size() < 100){
            hundred.emplace_back(rand(),rand());
        }
        std::cout << "Hundred Done\n";
        while(thousand.size() < 1000){
            thousand.emplace_back(rand(),rand());
        }
        std::cout << "Thousand Done\n";
        while(tenthousand.size() < 10000){
            tenthousand.emplace_back(rand(),rand());
        }
        std::cout << "Ten Thousand Done\n";
        while(hundredthousand.size() < 100000){
            hundredthousand.emplace_back(rand(),rand());
        }
        std::cout << "Hundred Thousand Done\n";
        while(million.size() < 1000000){
            million.emplace_back(rand(),rand());
        }
        std::cout << "Million Done\n";

        std::cout << "Ten:\n";
        test(ten);
        std::cout << "Hundred:\n";
        test(hundred);
        std::cout << "Thousand:\n";
        test(thousand);
        std::cout << "Ten Thousand:\n";
        test(tenthousand);
        std::cout << "Hundred Thousand:\n";
        test(hundredthousand);
        std::cout << "Million:\n";
        test(million);

//        std::vector<Point> P;
//
//        for (auto iter: i) {
//            std::cout << iter << "\n";
//        }
//        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
//                  << " nanoseconds\n";
//        output(i,"../hull.txt");
//        output(ten, "../test.txt");
    }
}