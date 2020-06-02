//
// Created by ian on 3/2/20.
//

#ifndef CONVEX_HULL_CONVEX_HULL_H
#define CONVEX_HULL_CONVEX_HULL_H

#include "Point/Point.h"
#include <vector>


class Hull {
protected:
public:
    virtual std::vector<Point> Convex_Hull()=0;
    virtual ~Hull(){};
};

#endif //CONVEX_HULL_CONVEX_HULL_H
