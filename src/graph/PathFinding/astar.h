#ifndef ASTAR_H
#define ASTAR_H

#include "point.h"
#include "astardata.h"
#include <list>
#include <algorithm>
#include <iostream>

class AStar
{
public:
    point end,start;
    point neighbours[8];
    std::list<AStarData> open;
    std::list<AStarData> close;
    int calcDist(point& p);
    bool isValid(point& p);
    bool existPoint(point& p, int cost);
    bool fillOpen(AStarData& n);
    bool search(point& s, point& e, map& mp);
    int path(std::list<point>& path);
    AStar();
};

#endif // ASTAR_H
