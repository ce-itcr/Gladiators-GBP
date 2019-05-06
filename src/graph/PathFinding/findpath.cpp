#include "findpath.h"



FindPath::FindPath(){
    QObject::connect(Populations::getInstance(),&Populations::readyPopulation,this,&FindPath::slotPath);
}

void FindPath::slotPath(){
    cout<<"1"<<endl;
    aStarPathFinding.m.updateMap(Map::getInstance()->getNodes(),0,0);
    cout<<"2"<<endl;
    if(aStarPathFinding.search(*start,*end,aStarPathFinding.m)){
        cout<<"3"<<endl;
        list<point> path;
        QList<Node *> list;
        int c = aStarPathFinding.path(path,Map::getInstance()->getNodes(),list);
        cout<<"4"<<endl;
        QList<Node *>::iterator i;
        for(i = list.begin(); i != list.end(); i++){
            cout << "(" << (*i)->getX() << ", " << (*i)->getY() << ")"<< endl << (*i)->isOccupied() << endl;
        }
        for(Gladiator *gladiator:*Populations::getInstance()->getGladiators()){
            gladiator->setNodePath(list);
            cout<<"5"<<endl;
        }
    }

}
