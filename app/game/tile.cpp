#include "tile.h"

Tile::Tile(QWidget *parent, int i, int j) : QFrame(parent)
{
    this->i = i;
    this->j = j;
    this->node = nullptr;
    this->setStyleSheet("background-color:#8B786D;");
}

int Tile::getI() const
{
    return i;
}

int Tile::getJ() const
{
    return j;
}

QRect Tile::getRect() const
{
    QRect rect(x(), y(), width(), height());
    return rect;
}

Node *Tile::getNode() const
{
    return node;
}

void Tile::setNode(Node *value)
{
    node = value;
}
