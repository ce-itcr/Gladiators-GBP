#ifndef ASTAR_H
#define ASTAR_H

#include "point.h"
#include "graph/PathFinding/astarmap.h"
#include "astardata.h"
#include "list.h"
#include "graph/node.h"
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
    int path(std::list<point>& path,const QList<Node *> &nodeList,QList<Node *> &pathList);
    int findNode(const QList<Node *> &nodeList,QList<Node *> &pathList, point pointToFind);
    AStar(int n);

};

#endif // ASTAR_H
