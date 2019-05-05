#include "enemy.h"

Enemy::Enemy(QWidget *parent) : QFrame(parent)
{
    tower = nullptr;
    tag = "enemy";
    x = 0;
    y = 0;
    width = 50;
    height = 50;
    target = nullptr;

    this->setStyleSheet("background-color:blue;");
    this->setGeometry(x, y, width, height);
    this->show();
}

void Enemy::update()
{
    this->move(x, y);
}

void Enemy::draw()
{

}

void Enemy::collide()
{

}

void Enemy::collide(QList<Entity *> players)
{
    if (players.isEmpty()) target = nullptr;
    else
    {
        target = closerPlayer(players);
        qDebug() << target;
    }

}

void Enemy::uncollide()
{

}

QRect Enemy::getRect()
{
    QRect rect(x, y, width, height);
    return rect;
}

QRegion Enemy::getCircle()
{
    int xPoss = x - width;
    int yPoss = y - height;
    int range = width * 3;
    QRegion circle(xPoss, yPoss, range, range, QRegion::Ellipse);
    return circle;
}

int Enemy::getX() const
{
    return x;
}

void Enemy::setX(int value)
{
    x = value;
}

int Enemy::getY() const
{
    return y;
}

void Enemy::setY(int value)
{
    y = value;
}

Tower *Enemy::getTower() const
{
    return tower;
}

void Enemy::setTower(Tower *value)
{
    tower = value;
}

Entity *Enemy::closerPlayer(QList<Entity *> players)
{
    Entity *closer = nullptr;
    float min = INFINITY;
    for (Entity *player : players)
    {
        QRect rect1 = this->getRect();
        QRect rect2 = player->getRect();

        int x1 = rect1.x();
        int y1 = rect1.y();
        int x2 = rect2.x();
        int y2 = rect2.y();

        int distance = Math::distance(x1, y1, x2, y2);
        if (distance < min) {
            closer = player;
            min = distance;
        }
    }
    return closer;
}
