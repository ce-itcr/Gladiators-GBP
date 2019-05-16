#include "astarmap.h"

AStarMap::AStarMap(int n){
    w = h = n;
    map = (int**) malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        map[i] = (int*) malloc(sizeof (int)*n);
    }
};

void AStarMap::updateMap(int row, int column){

    //    QList<Node *>::iterator i;
    //    for(i = nodeList.begin(); i != nodeList.end(); i++){
    //        map[(*i)->getX()][(*i)->getY()] = (*i)->isOccupied() ? 1 : 0;
    //        if(column == 15){
    //            cout << endl;
    //            column = 0;
    //            row++;
    //        }else{
    //            cout << (*i)->isOccupied();
    //            column++;
    //        }
    //    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            Node *node = Map::getInstance()->nodeAt(i,j);
            map[i][j] = node->isOccupied() ? 1 : 0;
        }
    }
};

int AStarMap::operator() (int x, int y){
    return this->map[x][y];
};
