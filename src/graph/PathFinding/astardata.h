#ifndef ASTARDATA_H
#define ASTARDATA_H

#include "point.h"

class AStarData
{
public:
    point pos, parent;
    int dist, cost;
    bool operator == (const AStarData& o);
    bool operator == (const point& o);
    bool operator < (const AStarData& o);
};

#endif // ASTARDATA_H
