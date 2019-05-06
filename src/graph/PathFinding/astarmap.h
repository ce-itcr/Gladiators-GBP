#ifndef ASTARMAP_H
#define ASTARMAP_H

#include <iostream>
#include <QList>
#include "graph/map.h"
#include "graph/node.h"

using namespace std;

class AStarMap
{
public:
    AStarMap(int n);
    int ** map;
    int w, h;
    void updateMap(int row, int column);
    int operator() (int x, int y);
};

#endif // ASTARMAP_H
