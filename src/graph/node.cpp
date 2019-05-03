#include "node.h"

Node::Node()
{
    entity = nullptr;
    occupied = false;
    neighbors = new QList<Node *>();
    x = 0;
    y = 0;
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

int Node::getX() const
{
    return x;
}

void Node::setX(int value)
{
    x = value;
}

int Node::getY() const
{
    return y;
}

void Node::setY(int value)
{
    y = value;
}
