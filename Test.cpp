//
// Created by ian on 4/5/20.
//


#include "Point/Point.h"
#include <vector>
#include <future>
#include <fstream>

void output(std::vector<Point> Output, std::string fileName){
    std::ofstream ifs(fileName);

    for(auto i: Output){
        ifs << i << "\n";
    }
    ifs.close();
}

int main(){
    std::vector<Point> ten, hundred, thousand, tenthousand, hundredthousand, million, tenmillion;

    int Ten = 10, Hundred = 100, Thousand = 1000, TenThousand = 10000, HundredThousand = 100000, Million = 1000000, TenMillion = 10000000;

    srand(time(nullptr));
    int a,b;
    while(tenmillion.size() != TenMillion){
        a = rand() % 10000;
        b = rand() % 10000;

        if(ten.size() != Ten)
            ten.emplace_back(a,b);

        if(hundred.size() != Hundred)
            hundred.emplace_back(a,b);

        if(thousand.size() != Thousand)
            thousand.emplace_back(a,b);

        if(tenthousand.size() != TenThousand)
            tenthousand.emplace_back(a,b);

        if(hundredthousand.size() != HundredThousand)
            hundredthousand.emplace_back(a,b);

        if(million.size() != Million)
            million.emplace_back(a,b);

        tenmillion.emplace_back(a,b);
    }

    auto TEN = std::async(output,ten,"ten.txt");
    auto HUNDRED = std::async(output, hundred,"hundred.txt");
    auto THOUSAND = std::async(output,thousand,"thousand.txt");
    auto TENTHOUSAND = std::async(output,tenthousand,"tenthousand.txt");
    auto HUNDREDTHOUSAND = std::async(output,hundredthousand,"hundredthousand.txt");
    auto MILLION = std::async(output,million, "million.txt");
    auto TENMILLION = std::async(output,tenmillion, "tenmillion.txt");

}