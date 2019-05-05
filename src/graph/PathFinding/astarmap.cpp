#include "astarmap.h"

AStarMap::AStarMap(int n){
    w = h = n;
};

void AStarMap::updateMap(QList<QList<Node *> *> matrixList, int row, int column){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            map[i][j] = matrixList.front()->front()->isOccupied() ? 1 : 0;
            matrixList.front()->erase(0);
        }
        matrixList.erase(0);
    }
};

int AStarMap::operator() (int x, int y){
    return this->map[x][y];
};
