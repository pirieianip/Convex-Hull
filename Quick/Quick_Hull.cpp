//
// Created by ian on 3/29/20.
//

#include "Quick_Hull.h"
#include <future>
#include <utility>
//#include <iostream>

std::vector<Point> Quick_Hull::Convex_Hull() {
    return Data;
}

Quick_Hull::Quick_Hull(std::vector<Point> Input){
    switch(std::thread::hardware_concurrency()){
        case 1:
            type = singleThread;
            break;
        case 2:
            type = doubleThread;
            break;
        default:
            type = multiThread;
            break;
    }
    Quick_Hull Control(std::move(Input), type);
    Data = std::move(Control.Data);
}



Quick_Hull::Quick_Hull(std::vector<Point> Input, thread_test_type typ): type(typ) {
    std::vector<Point> Left, Right;
    Point y_max = Input[0], y_min = Input[0];
    bool full = false;
    for(auto i :Input){
        if(y_max.getY() < i.getY())
            y_max = i;
        if(y_min.getY() > i.getY())
            y_min = i;
    }

    Line Center(y_min, y_max);

    for(auto i: Input){
        if(Center > i && i != y_max && i != y_min)
            Left.emplace_back(i);
        else if(Center < i && i != y_max && i != y_min)
            Right.emplace_back(i);
//        else
//            std::cout << "knocked off" << i << "\n";
    }

    std::vector<Point> Results1, Results2;

    if(type == singleThread)
    {
        if(Left.size() > 2) {
            Results1 = Quick_Single_Full(Left, Center);
            full = true;
        }
        else
            Results1 = Quick_Single(Left, Center);

        if(!full && Right.size() > 2) {
            Results2 = Quick_Single_Full(Right, Center);
            full = true;
        } else
            Results2 = Quick_Single(Right, Center);

        if(full){
            if(!Results1.empty())
                Data.insert(Data.end(), Results1.begin(), Results1.end());

            if(!Results2.empty())
                Data.insert(Data.end(), Results2.begin(), Results2.end());
        } else {
            Data.emplace_back(y_min);

            if(!Results1.empty())
                Data.insert(Data.end(), Results1.begin(), Results1.end());

            Data.emplace_back(y_max);

            if(!Results2.empty())
                Data.insert(Data.end(), Results2.begin(), Results2.end());
        }
    }
    else if(type == doubleThread) {
        std::future<std::vector<Point>> a,b;
        if(Left.size() > 2) {
            a = std::async(std::launch::async, Quick_Single_Full, Left, Center);
            full = true;
        }
        else
            a = std::async(std::launch::async, Quick_Single, Left, Center);


        if(!full && Right.size() > 2) {
            b = std::async(std::launch::deferred, Quick_Single_Full, Right, Center);
            full = true;
        } else
            b = std::async(std::launch::deferred, Quick_Single, Right, Center);

        if(full){
            if(!Results1.empty())
                Data.insert(Data.end(), Results1.begin(), Results1.end());

            if(!Results2.empty())
                Data.insert(Data.end(), Results2.begin(), Results2.end());
        } else {
            Data.emplace_back(y_min);

            if(!Results1.empty())
                Data.insert(Data.end(), Results1.begin(), Results1.end());

            Data.emplace_back(y_max);

            if(!Results2.empty())
                Data.insert(Data.end(), Results2.begin(), Results2.end());
        }
    }
    else if(type == multiThread) {
        mutexClass::setMaxThreads();
        Quick_Struct side1(Left, Center), side2(Right, Center);
        std::future<std::vector<Point>> a,b;
        if(Left.size() > 2) {
            mutexClass::makeThread();
            a = std::async(std::launch::async, Quick_Full, side1);
            full = true;
        }
        else if(!Left.empty()) {
            mutexClass::makeThread();
            a = std::async(std::launch::async, Quick, side1);
        }

        if(!full && Right.size() > 2) {
            mutexClass::makeThread();
            b = std::async(std::launch::async, Quick_Full, side2);
            full = true;
        } else if(!Right.empty()){
            mutexClass::makeThread();
            b = std::async(std::launch::async, Quick, side2);
        }
        if(full){
            if(!Left.empty()) {
                Results1 = a.get();
                mutexClass::endThread();
                if (!Results1.empty())
                    Data.insert(Data.end(), Results1.begin(), Results1.end());
            }
            if(!Right.empty()) {
                Results2 = b.get();
                mutexClass::endThread();
                if (!Results2.empty())
                    Data.insert(Data.end(), Results2.begin(), Results2.end());
            }
        } else {
            Data.emplace_back(y_min);
            if(!Left.empty()) {
                Results1 = a.get();
                mutexClass::endThread();
                if (!Results1.empty())
                    Data.insert(Data.end(), Results1.begin(), Results1.end());
            }
            Data.emplace_back(y_max);
            if(!Right.empty()) {
                Results2 = b.get();
                mutexClass::endThread();
                if (!Results2.empty())
                    Data.insert(Data.end(), Results2.begin(), Results2.end());
            }
        }
    }
    else{
        throw std::invalid_argument("Null case thrown");
    }
}

Quick_Hull::~Quick_Hull() {

}




