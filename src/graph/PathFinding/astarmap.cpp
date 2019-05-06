#include "astarmap.h"

AStarMap::AStarMap(int n){
    w = h = n;
    map = (int**) malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        map[i] = (int*) malloc(sizeof (int)*n);
    }
};

void AStarMap::updateMap(QList<Node *> nodeList, int row, int column){
    cout<<"1.5"<<endl;
    cout<<w<<endl;
    QList<Node *>::iterator i;
    cout << nodeList.size() << endl;
    for(i = nodeList.begin(); i != nodeList.end(); i++){
        map[(*i)->getX()][(*i)->getY()] = (*i)->isOccupied() ? 1 : 0;
        cout << (*i)->isOccupied() << endl;
    }
//    for (int i = 0; i < row; ++i) {
//        for (int j = 0; j < column; ++j) {
//            map[i][j] = matrixList.front()->front()->isOccupied() ? 1 : 0;
//            matrixList.front()->erase(0);
//        }
//        matrixList.erase(0);
//    }
};

int AStarMap::operator() (int x, int y){
    return this->map[x][y];
};
