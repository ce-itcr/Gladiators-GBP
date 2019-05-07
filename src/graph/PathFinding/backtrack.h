#ifndef BACKTRACK_H
#define BACKTRACK_H

#include "graph/PathFinding/vector.h"
#include "graph/PathFinding/list.h"
#include "graph/node.h"
#include "graph/map.h"
#include "list.h"

class Backtrack
{
public:

    int w, h;
    Vector start = Vector(0,0);
    Vector finish = Vector(14,14);// Vector((Map::getInstance()->getRows())-1,(Map::getInstance()->getRows())-1);
    int endX;
    int endY;
    int ** map;
    List Path;
    int finalValue = 10000;
    void PathfindingBackTrack(int x, int y, int value, List *list);
    Backtrack(int endY,int endX,int finalValue,Vector start,Vector finish,int n);
    void NodeToArray(const QList<Node *> nodeList, int row, int column);
private:

};

#endif // BACKTRACK_H
