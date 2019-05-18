#ifndef FINDPATH_H
#define FINDPATH_H

#include <iostream>
#include "game/populations.h"
#include "graph/map.h"
#include "astar.h"
#include "backtrack.h"
#include "point.h"

using namespace std;

class FindPath
{

public:

    FindPath static *instance;
    AStar aStarPathFinding = *new AStar(Map::getInstance()->getRows());
    Backtrack backTrackPathFinding = *new Backtrack((Map::getInstance()->getRows())-1,(Map::getInstance()->getRows())-1,10000,*new Vector(0,0),
                                                  *new Vector((Map::getInstance()->getRows())-1,(Map::getInstance()->getRows())-1),
                                                  Map::getInstance()->getRows());
    point *start;
    point *end = new point ((Map::getInstance()->getRows())-1,(Map::getInstance()->getRows())-1);
    int pathCost = 10000;
    void shortestPath();
    FindPath();
    int counter = 1;
private:

};

#endif // FINDPATH_H
