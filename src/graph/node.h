#ifndef NODE_H
#define NODE_H

#include "game/entities/entity.h"

#include <QList>

class Node
{
public:
    Node();

    void addNeighbor(Node *node);

    Entity *getEntity() const;
    void setEntity(Entity *value);

    bool isOccupied() const;
    void setOccupied(bool value);

    QList<Node *> *getNeighbors() const;
    void setNeighbors(QList<Node *> *value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    Entity *entity;
    bool occupied;
    QList<Node *> *neighbors;
    int x;
    int y;
};

#endif // NODE_H
