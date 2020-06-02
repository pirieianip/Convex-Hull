//
// Created by ian on 3/5/20.
//

#include "Graham.h"
#include <future>
#include <algorithm>

std::vector<Point> Graham::Sort(const std::vector<Point> &Input) {
//    std::cout << "init\n";
    Bottom = Input[0];
    Top = Input[0];
    Left = Input[0];
    Right = Input[0];
    for (auto &i: Input) {
        if(i < Bottom)
            Bottom = i;
        if(i > Top)
            Top = i;
        if(i.getX() <= Left.getX() && i.getY() >= Left.getY())
            Left = i;
        if(i.getX() >= Right.getX() && i.getY() <= Right.getY())
            Right = i;
    }
//    std::cout << "Min\n";

    std::vector<Line> Lines;

    unsigned int thread_count = std::thread::hardware_concurrency();

    std::vector<std::vector<Point>> Sectional(thread_count);

    for(int i = 0; i < Input.size(); ++i){
        if(Input[i] != Bottom)
            Sectional[i%thread_count].emplace_back(Input[i]);
    }

    std::vector<std::future<std::vector<Line>>> futures;
    std::vector<std::vector<Line>> many_lines(Sectional.size());

    for(auto & i : Sectional){
        futures.emplace_back(std::async(std::launch::async, Future_Lines,i,Bottom));
    }

    for(auto & i: futures){
        auto v = i.get();
        Lines.insert(Lines.end(),v.begin(),v.end());
    }

//    std::cout << "futures\n";


//    std::sort(Lines.begin(), Lines.end(), [](const Line& a, const Line& b){
//        return (sin(a.getP2()-a.getP1()) - sin(b.getP2()-b.getP1()));
//    });

    std::qsort(&Lines[0],Lines.size(),sizeof(Lines[0]),compare);

//    std::cout << "Sort:\n";
//    for(auto i: Lines){
//        std::cout << i << " Angle: " << sinLine(i) << "\n";
//    }

//    std::cout << "Bottom: " << Bottom << "\n";

    std::vector<Point> ret;
    ret.emplace_back(Bottom);

    for(auto i: Lines)
        ret.emplace_back(i.getP2());
    ret.emplace_back(Bottom);

//    for(auto &i: ret)
//        std::cout << i << "\n";

    return ret;
}


