//
// Created by ian on 3/2/20.
//


#include "Graham.h"

Graham::Graham(const std::vector<Point>& Input) :
    found_Top(false),
    found_Left(false),
    found_Right(false)
{
    if(Input.empty())
        return;

    Data = Push_Pop(Sort(Input));
//    std::cout << "Input size: " << Input.size() << "\n";
//    for(int i = 0; i < Input.size(); ++i){
//        std::cout << "Input " << i << ": " << Input[i] << "\n";
//    }

//    std::cout << "\n\nResults: " << Data.size() << "\n";
//
//    for(int i = 0; i < Data.size(); ++i){
//        std::cout << "Result " << i << ": " << Data[i] << "\n";
//    }

}

Graham::~Graham() {

}



