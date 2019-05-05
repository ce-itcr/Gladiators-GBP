#include "astardata.h"

bool AStarData::operator == (const AStarData& o ) {
    return pos == o.pos;
}

bool AStarData::operator == (const point& o ) {
    return pos == o;
}

bool AStarData::operator < (const AStarData& o ) {
    return dist + cost < o.dist + o.cost;
}
