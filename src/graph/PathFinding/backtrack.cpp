#include "graph/PathFinding/backtrack.h"



Backtrack::Backtrack(int endY,int endX,int finalValue,Vector start,Vector finish,int n){
    this->endY = endY;
    this->endX = endX;
    this->finalValue = finalValue;
    this->start = start;
    this->finish = finish;
    w = h = n;
    map = (int**) malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        map[i] = (int*) malloc(sizeof (int)*n);
    }
}

void Backtrack::NodeToArray(const QList<Node *> nodeList, int row, int column){
    QList<Node *>::const_iterator i;
    for(i = nodeList.begin(); i < nodeList.end(); i++){
        if(column > h){
            column = 0;
            row++;
        }else{
            map[row][column] = (*i)->isOccupied() ? 1 : 0;
        }
    }
//    for (int i = 0; i < row; ++i) {
//        for (int j = 0; j < column; ++j) {
//            map[i][j] = matrixList.front()->front()->isOccupied() ? 1 : 0;
//            matrixList.front()->erase(0);
//        }
//        matrixList.erase(0);
//    }
}

void Backtrack::PathfindingBackTrack(int x, int y, int value, List *list){

    Vector *newVector = new Vector(x, y);
    bool exist = list->search(newVector);


    if(y + 1 < 15 && map[x][y + 1] != 1 &&
    ((x == endX && y != endY) || (x != endX && y != endY) || (x != endX && y == endY)) && !exist && value < finalValue) {
        list->add_head(newVector);
        PathfindingBackTrack(x, y + 1, finalValue + 1, list);
        list->del_by_data(newVector);
    }
    if (x - 1 >= 0 && map[x - 1][y] != 1 &&
    ((x == endX && y != endY) || (x != endX && y != endY) || (x != endX && y == endY)) && !exist && value < finalValue) {
        list->add_head(newVector);
        PathfindingBackTrack(x - 1, y, finalValue + 1, list);
        list->del_by_data(newVector);
    }
    if (x + 1 < 15 && map[x + 1][y] != 1 &&
    ((x == endX && y != endY) || (x != endX && y != endY) || (x != endX && y == endY)) && !exist && value < finalValue) {
        list->add_head(newVector);
        PathfindingBackTrack(x + 1, y, finalValue + 1, list);
        list->del_by_data(newVector);
    }
    if(x == endX && y == endY){
        list->add_head(newVector);
        if(finalValue > value){
            finalValue = value;
            while(list->m_head){
                Path.add_end(list->m_head->element);
                list->del_by_data(0);
            }
            Path.print();
        }
        list->del_by_data(newVector);
    }
}
