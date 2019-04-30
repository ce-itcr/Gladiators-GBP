#include "enemy.h"

Enemy::Enemy(QWidget *parent) : QFrame(parent)
{
    x = 0;
    y = 0;
    width = 50;
    height = 50;

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

void Enemy::uncollide()
{

}

QRect Enemy::getRect()
{
    QRect rect(x, y, width, height);
    return rect;
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
