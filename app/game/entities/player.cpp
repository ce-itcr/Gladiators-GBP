#include "player.h"
#include <QMovie>
#include <QLabel>

Player::Player(QWidget *parent) : QFrame (parent), grid(static_cast<Grid *>(parent))
{
    gladiator = nullptr;
    tag = "player";
    x = 0;
    y = 0;
    width = 50;
    height = 50;
    xAcc = 1;
    yAcc = 1;
    maxSpeed = 10;
    maxAcc = 2;
    canMove = true;
    target = nullptr;
    nodeIndex = 0;
//    setStyleSheet("image: url(:img/gladiatorRun.gif)");

    this->setStyleSheet("background-color:green;");
    this->setGeometry(x, y, width, height);
    this->show();
}

void Player::update()
{
    if (target == nullptr) nextTarget();
    if (canMove && target != nullptr) move();
}

void Player::draw()
{
}

void Player::collide()
{
    //canMove = false;
}

void Player::uncollide()
{
    canMove = true;
}

QRect Player::getRect()
{
    QRect rect(x, y, width, height);
    return rect;
}

int Player::getX() const
{
    return x;
}

void Player::setX(int value)
{
    x = value;
}

int Player::getY() const
{
    return y;
}

void Player::setY(int value)
{
    y = value;
}

QList<Node *> Player::getNodePath() const
{
    return nodePath;
}

void Player::setNodePath(const QList<Node *> &value)
{
    nodePath = value;
}

Gladiator *Player::getGladiator() const
{
    return gladiator;
}

void Player::setGladiator(Gladiator *value)
{
    gladiator = value;
}

void Player::move()
{
    xSpeed = Math::clamp(0, maxSpeed, xSpeed + xAcc);
    ySpeed = Math::clamp(0, maxSpeed, ySpeed + yAcc);
    x = Math::approach(x, target->x(), xSpeed);
    y = Math::approach(y, target->y(), ySpeed);;
    
    QFrame::move(x, y);
    if (x == target->x() && y == target->y()) target = nullptr;
}

void Player::nextTarget()
{
    Node *node = nodePath.value(nodeIndex);
    QList<Tile *> tiles = grid->getTiles();
    for (Tile *tile : tiles)
    {
        if (tile->getNode() == node)
        {
            nodeIndex++;
            target = tile;
            break;
        }
    }
}
