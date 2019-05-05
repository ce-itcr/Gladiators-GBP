#ifndef MAP_H
#define MAP_H

#include <QList>
#include "graph/node.h"

class AStarMap
{
public:
    AStarMap(int n);
    int ** map;
    int w, h;
    void updateMap(QList<QList<Node *> *> matrixList, int row, int column);
    int operator() (int x, int y);
};

#endif // MAP_H
