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



void Backtrack::PathfindingBackTrack(int x, int y, int value, List *list){
    Vector *newVector = new Vector(x, y);
    if(!list->search(newVector) && Path->m_head == NULL){
        //abajo
        if (x + 1 < 15 && map[x + 1][y] != 1 &&
                ((x == endX && y != endY) || (x != endX && y != endY) || (x != endX && y == endY)) && value < finalValue) {
            list->add_head(newVector);
            PathfindingBackTrack(x + 1, y, value + 1, list);
            list->del_by_data(newVector);
        }
        //derecha
        if(y + 1 < 15 && map[x][y + 1] != 1 &&
                ((x == endX && y != endY) || (x != endX && y != endY) || (x != endX && y == endY)) && value < finalValue) {
            list->add_head(newVector);
            PathfindingBackTrack(x, y + 1, value + 1, list);
            list->del_by_data(newVector);
        }
        //izquierda
        if (y - 1 >= 0 && map[x][y - 1] != 1 &&
                ((x == endX && y != endY) || (x != endX && y != endY) || (x != endX && y == endY)) && value < finalValue) {
            list->add_head(newVector);
            PathfindingBackTrack(x, y - 1, value + 1, list);
            list->del_by_data(newVector);
        }
        //arriba
        if (x - 1 >= 0 && map[x - 1][y] != 1 &&
                ((x == endX && y != endY) || (x != endX && y != endY) || (x != endX && y == endY)) && value < finalValue) {
            list->add_head(newVector);
            PathfindingBackTrack(x - 1, y, value + 1, list);
            list->del_by_data(newVector);
        }
        if(x == endX && y == endY){
            list->add_head(newVector);
            if(finalValue > value){
                finalValue = value;
                list->print();
                NodeLinkedList *temp = list->getM_head();
                while(temp){
                    Path->add_head(temp->element);
                    temp = temp->next;
                }
            }
            list->del_by_data(newVector);
        }
    }
}

void Backtrack::vectorListToQList(const QList<Node *> &QListGame,QList<Node *> &QListBackTrack)
{
    while(this->Path->m_head != NULL){
        int x =this->Path->m_head->element->getX();
        int y =this->Path->m_head->element->getY();
        findNode(QListGame, QListBackTrack, this->Path->m_head->element);
        Path->del_by_data(Path->m_head->element);
    }
    finalValue = 10000;
}

void Backtrack::findNode(const QList<Node *> &nodeList,QList<Node *> &pathList, Vector *vectorToFind){
    QList<Node *>::const_iterator i;
    for(i = nodeList.begin(); i != nodeList.end(); i++){
        if((*i)->getX() == vectorToFind->getX() && (*i)->getY() == vectorToFind->getY()){
            pathList.push_back(*i);
        }
    }
}
