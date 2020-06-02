//
// Created bgetY() ian on 3/2/20.
//

#include <thread>
#include <iostream>
#include "Jarvis.h"



int orient(Point a, Point b, Point c) {
    int v = (b.getY() - a.getY()) * (c.getX() - b.getX()) - (b.getX() - a.getX()) * (c.getY() - b.getY());
    if (v == 0)
        return 0; // colinear
    return (v >0) ? 1 : 2; // clock or counterclock wise
}

Jarvis::Jarvis(const std::vector<Point> &Input){
    // There must be at least 3 points
    if (Input.size() < 3) return;

    // Initialize Result

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < Input.size(); i++)
        if (Input[i].getX() < Input[l].getX())
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do
    {
        // Add current point to result
        Data.emplace_back(Input[p]);

        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%Input.size();
        for (int i = 0; i < Input.size(); i++)
        {
            // If i is more counterclockwise than current q, then
            // update q
            if (orient(Input[p], Input[i], Input[q]) == 2)
                q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    } while (p != l);  // While we don't come to first point

    // Print Result
}

Jarvis::~Jarvis() {

}



