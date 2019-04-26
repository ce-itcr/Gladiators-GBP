#include "node.h"

Node::Node()
{
    entity = nullptr;
    occupied = false;
}

Entity *Node::getEntity() const
{
    return entity;
}

void Node::setEntity(Entity *value)
{
    entity = value;
}

bool Node::isOccupied() const
{
    return occupied;
}

void Node::setOccupied(bool value)
{
    occupied = value;
}
