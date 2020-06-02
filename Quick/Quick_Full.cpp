//
// Created by ian on 3/30/20.
//
#include "mutexClass.h"
#include "Quick_Hull.h"

std::vector<Point> Quick_Hull::Quick_Full(Quick_Struct Data) {
    // Check for empty
    if(Data.Points.size() <= 1)
        return Data.Points;

    // Create vectors
    std::vector<Point> Left, Right, retRight, retLeft, ret;

    // Create async futures
    std::future<std::vector<Point>> lfunc, rfunc;

    // make checks for threads;
    bool rightbool = false, leftbool = false;

    // Create inital Largest
    Triangle Largest(Data.initial_line, Data.Points[0]);

    // Find Actual Largest Triangle
    for(auto i: Data.Points){
        Triangle checkLarger(Data.initial_line,i);
        if(checkLarger.getCHeight() > Largest.getCHeight())
            Largest = checkLarger;
    }

    // Create Centerline using Centroid
    Line CenterLine(Largest.getCentroid(), Largest.getPointC());

    // Find useful points and divide them.
    for(auto i: Data.Points){
        if(!Largest.isInside(i)) {
            if(CenterLine > i)
                Left.emplace_back(i);
            else if(CenterLine < i)
                Right.emplace_back(i);
        }
    }

    // Create Data Structures for Quick.


    // Use mutex to check if there is a thread.
    // If thread is available create async thread
    // else create async deferred thread
    // For Left Side
    if(!Left.empty() && mutexClass::makeThread()) {
        Quick_Struct L(Left,Largest.getSideB());
        lfunc = std::async(std::launch::async, Quick, L);
        leftbool = true;
    }
    else {
        Quick_Struct L(Left,Largest.getSideB());
        lfunc = std::async(std::launch::deferred, Quick, L);
    }

    // See comment above for Right side
    if(!Right.empty() && mutexClass::makeThread()) {
        Quick_Struct R(Right, Largest.getSideA());
        rfunc = std::async(std::launch::async, Quick, R);
        rightbool = true;
    }
    else {
        Quick_Struct R(Right, Largest.getSideA());
        rfunc = std::async(std::launch::deferred, Quick, R);
    }

    // Add Left Point of Largest to ret
    ret.emplace_back(Largest.getPointA());

    // Get returned vector to retLeft from async function.
    retLeft = lfunc.get();

    // if retLeft is not empty, insert into ret.
    if(!retLeft.empty())
        ret.insert(ret.end(), retLeft.begin(),retLeft.end());

    // If there was a thread created, release thread.
    if(leftbool)
        mutexClass::endThread();

    // Add Largest Point to the Mix
    ret.emplace_back(Largest.getPointC());

    // Get Returned vector from async function.
    retRight = rfunc.get();

    // If there was a thread created, release thread.
    if(rightbool)
        mutexClass::endThread();

    // if retRight is not empty, add it to ret.
    if(!retRight.empty())
        ret.insert(ret.end(), retRight.begin(),retRight.end());

    // Add Left Point of Largest to ret
    ret.emplace_back(Largest.getPointB());

    // return ret
    return ret;
}