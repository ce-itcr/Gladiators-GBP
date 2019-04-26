#include "node.h"

Node::Node()
{
    entity = nullptr;
    occupied = false;
    neighbors = new QList<Node *>();
}

void Node::addNeighbor(Node *node)
{
    neighbors->push_back(node);
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

QList<Node *> *Node::getNeighbors() const
{
    return neighbors;
}

void Node::setNeighbors(QList<Node *> *value)
{
    neighbors = value;
}
