#ifndef FINDPATH_H
#define FINDPATH_H

#include <QList>
#include <iostream>
#include "game/populations.h"
#include "graph/map.h"
#include "astar.h"
#include "backtrack.h"
#include "point.h"

using namespace std;

class FindPath : public QObject
{
    Q_OBJECT
public:

    FindPath();

    AStar aStarPathFinding = *new AStar(Map::getInstance()->getRows());
    Backtrack backTrackPathFinding = *new Backtrack((Map::getInstance()->getRows())-1,(Map::getInstance()->getRows())-1,10000,*new Vector(0,0),
                                                  *new Vector((Map::getInstance()->getRows())-1,(Map::getInstance()->getRows())-1),
                                                  Map::getInstance()->getRows());
    point *start = new point(0,0);
    point *end = new point ((Map::getInstance()->getRows())-1,(Map::getInstance()->getRows())-1);
signals:

private:

public slots:
    void slotPath();
};

#endif // FINDPATH_H
