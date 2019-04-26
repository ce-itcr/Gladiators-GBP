#ifndef NODE_H
#define NODE_H

#include "game/entities/entity.h"

class Node
{
public:
    Node();

    Entity *getEntity() const;
    void setEntity(Entity *value);

    bool isOccupied() const;
    void setOccupied(bool value);

private:
    Entity *entity;
    bool occupied;
};

#endif // NODE_H
