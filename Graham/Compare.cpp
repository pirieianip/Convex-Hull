//
// Created by ian on 3/6/20.
//

#include "Graham.h"

int Graham::compare(const void *a, const void *b) {
    if (sinLine(*(Line*)a) > sinLine(*(Line*)b))
        return -1;
    return 1;
}