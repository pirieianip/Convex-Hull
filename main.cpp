#include <iostream>
#include <chrono>
#include "Graham/Graham.h"
#include "Helpers/Helper.h"

int main(int args, char** argv) {
    if(args < 3) {
        std::cout << "Too few arguements\n\n";
        return 0;
    }

    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    auto input = getPoints(argv[2]);

    if(argv[1][0] == 'J' || argv[1][0] == 'j'){
        start = std::chrono::steady_clock::now();
        Jarvis jarv(input);
        end = std::chrono::steady_clock::now();
        auto i = jarv.Convex_Hull();
        output(i,"hull.txt");
    }
    else if(argv[1][0] == 'G' || argv[1][0] == 'g') {
        start = std::chrono::steady_clock::now();
        Graham grah(input);
        end = std::chrono::steady_clock::now();
        auto i = grah.Convex_Hull();
        output(i,"hull.txt");
    } else if(argv[1][0] == 'q' || argv[1][0] == 'Q' ) {
        start = std::chrono::steady_clock::now();
        Quick_Hull quick(input);
        end = std::chrono::steady_clock::now();
        auto i = quick.Convex_Hull();
        output(i,"hull.txt");
    } else {
        std::cout << "Illegal input:\n"
                  << "Q/q: Quickhull\n"
                  << "J/j: Jarvis March\n"
                  << "G/g: Graham Scan\n";
        return 0;
    }

    std::cout << "size of array: " << input.size() << "\n"
              << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\n";
    return 0;
}
