#ifndef ASTAR_H
#define ASTAR_H

#include "point.h"
#include "astarmap.h"
#include "astardata.h"
#include "list.h"
#include <QList>
#include <list>
#include <algorithm>
#include <iostream>

class AStar
{
public:
    AStarMap m = NULL;
    point end,start;
    point neighbours[8];
    std::list<AStarData> open;
    std::list<AStarData> closed;
    int calcDist(point& p);
    bool isValid(point& p);
    bool existPoint(point& p, int cost);
    bool fillOpen(AStarData& n);
    bool search(point& s, point& e, AStarMap& mp);
    int path(std::list<point>& path, QList<Node *> &nodeList,QList<Node *> &pathList);
    int findNode(QList<Node *> &nodeList,QList<Node *> &pathList, point pointToFind);
    AStar();

};

#endif // ASTAR_H
