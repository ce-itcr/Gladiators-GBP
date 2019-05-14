#include "findpath.h"


FindPath *FindPath::instance = new FindPath();

FindPath::FindPath(){

}

void FindPath::shortestPath(){
    aStarPathFinding.m.updateMap(Map::getInstance()->getRows(),Map::getInstance()->getColumns());
    backTrackPathFinding.map = aStarPathFinding.m.map;

    start = new point(0,0);
    if(aStarPathFinding.search(*start,*end,aStarPathFinding.m)){
        list<point> path;
        QList<Node *> list;
        pathCost = aStarPathFinding.path(path,Map::getInstance()->getNodes(),list);
        path.clear();
        list.clear();
    }else{
        pathCost = 10000;
    }
    int lineas = 0;
    if(pathCost != 10000){
        if(!counter){
            for(Gladiator *gladiator:*Populations::getInstance()->getGladiators()){
                start = new point(gladiator->getI(),gladiator->getJ());
                if(aStarPathFinding.search(*start,*end,aStarPathFinding.m)){
                    list<point> path;
                    QList<Node *> list;
                    pathCost = aStarPathFinding.path(path,Map::getInstance()->getNodes(),list);
                    gladiator->setNodePath(list);
                    path.clear();
                    list.clear();
                }
            }
            counter++;
        }else{
            for (Gladiator *gladiator:*Populations::getInstance()->getGladiators()) {
                cout << "(" << gladiator->getI() << ", " << gladiator->getJ() << ")" << endl;
                List *listTemp = new List();
                QList<Node *> listQ;
                backTrackPathFinding.PathfindingBackTrack(gladiator->getI(),gladiator->getJ(), 0, listTemp);
                backTrackPathFinding.vectorListToQList(Map::getInstance()->getNodes(),listQ);
                gladiator->setNodePath(listQ);
                listQ.clear();
                delete listTemp;
                lineas++;
            }
            counter--;
            cout << lineas << endl;
        }
    }
}
