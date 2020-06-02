//
// Created by ian on 3/29/20.
//

#ifndef CONVEX_HULL_MUTEXCLASS_H
#define CONVEX_HULL_MUTEXCLASS_H
#pragma once
#include <mutex>
#include <future>

static std::mutex mut;
static unsigned maxThreads;
static int threads;

class mutexClass{

public:
    static void setMaxThreads(){
        maxThreads = std::thread::hardware_concurrency();
        threads = 0;
    };

    static bool makeThread(){
        bool check = false;
        std::lock_guard<std::mutex> Lock(mut);
        if(threads < maxThreads){
            ++threads;
            check = true;
        }
        return check;
    }

    static void endThread(){
        std::lock_guard<std::mutex> Lock(mut);
        if(threads == 0)
            throw std::logic_error("threads cannot be less then 0");
        --threads;
        mut.unlock();
    }
};

#endif //CONVEX_HULL_MUTEXCLASS_H
