//
// Created by ian on 3/8/20.
//

#include <iostream>
#include <algorithm>
#include "Jarvis.h"



void Jarvis::Jarvis_March(const std::vector<Point> &Input) {
    if(Data.front() != Data.back()) {
        std::vector<Point> Cont;

        bool direction = false, check = false;
        Line Check_Line;
        Line Deletor(*Data.end(), *Data.begin());

        for (auto i: Input) {
            if (i != *(Data.end()) && i != *(Data.end() - 1)) {
                Check_Line = Line(*Data.end(), i);
                direction = Check_Line > *(Data.end() - 1);
                check = true;
                break;
            }
        }
        if (!check) {
            throw std::logic_error("March failure");
        }
        if (direction) {
            for (auto i: Input) {
                if(i != Data.back()) {
                    if (Check_Line < i) {
                        Check_Line = Line(*Data.end(), i);
                    }
                    if (Check_Line == i && (Line(*Data.end(), i).getMag() > Check_Line.getMag())) {
                        Check_Line = Line(*Data.end(), i);
                    }
                }
                if (Deletor <= i)
                    Cont.emplace_back(i);
            }
            if(Check_Line > Data.front()){
                Data.emplace_back(Check_Line.getP2());
                Jarvis_March(Cont);
            }
        } else {
            for (auto i: Input) {
                if(i != Data.back()) {
                    if (Check_Line > i) {
                        Check_Line = Line(*Data.end(), i);
                    }
                    if (Check_Line == i && (Line(*Data.end(), i).getMag() > Check_Line.getMag())) {
                        Check_Line = Line(*Data.end(), i);
                    }
                }
                if (Deletor >= i)
                    Cont.emplace_back(i);
            }
            if(Check_Line > Data.front()){
                Data.emplace_back(Check_Line.getP2());
                Jarvis_March(Cont);
            }
        }


    }
}

