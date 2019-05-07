#include "tile.h"

Tile::Tile(QWidget *parent, int i, int j) : QFrame(parent)
{
    this->i = i;
    this->j = j;
    this->node = nullptr;
    this->build = false;
}

void Tile::setup(QChar qchar)
{
    if (qchar == '.'){  // Walkable and Buildable
        build = true;
        node->setOccupied(false);
        setStyleSheet("background-color:#8B786D;");  // Road
    }
    if (qchar == '0'){  // Wall
        node->setOccupied(true);
        setStyleSheet("background-color:#504b58;");
    }
    if (qchar == '-'){  // Walkable
        node->setOccupied(false);
        setStyleSheet("background-color:#8B786D;");  // Road
    }
//    if (qchar == 'B'){  // Buildable
//        build = true;
//        setStyleSheet("background-color:#635255;"
//                      "image: url(:img/buildIcon.png)");
//    }
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

bool Tile::canBuild() const
{
    return build;
}

void Tile::setCanBuild(bool value)
{
    build = value;
}
