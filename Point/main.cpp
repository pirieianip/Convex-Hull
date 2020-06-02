//
// Created by ian on 3/9/20.
//
#pragma once

#include <iostream>
#include "Point.h"

int main(){
    Point p(3,4);

    if(p.getHypot() == 5)
        std::cout << "Hypot true";
}