//
// Created by ian on 3/8/20.
//

#ifndef CONVEX_HULL_HELPER_H
#define CONVEX_HULL_HELPER_H

#include <fstream>
#include "../Convex_Hull.h"

void output(std::vector<Point> Data, std::ostream& out);

void output(std::vector<Point>& Data, std::string output_file);

std::vector<Point> getPoints(std::string file);

#endif //CONVEX_HULL_HELPER_H
