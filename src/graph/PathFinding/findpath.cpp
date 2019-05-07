#include "findpath.h"


FindPath *FindPath::instance = new FindPath();

FindPath::FindPath(){

}

void FindPath::shortestPath(){
    aStarPathFinding.m.updateMap(Map::getInstance()->getRows(),Map::getInstance()->getColumns());

    if(aStarPathFinding.search(*start,*end,aStarPathFinding.m)){
        list<point> path;
        QList<Node *> list;
        pathCost = aStarPathFinding.path(path,Map::getInstance()->getNodes(),list);
        cout << pathCost << endl;
        for(Gladiator *gladiator:*Populations::getInstance()->getGladiators()){
            gladiator->setNodePath(list);
        }
    }else{
        pathCost = 10000;
    }

}
