#include "player.h"

Player::Player(QWidget *parent) : QFrame (parent)
{
    x = 0;
    y = 0;
    width = 50;
    height = 50;
    acc = 1;
    maxSpeed = 10;
    maxAcc = 2;
    canMove = true;

    this->setStyleSheet("background-color:green;");
    this->setGeometry(x, y, width, height);
    this->show();
}

void Player::update()
{
    if (canMove) move();
}

void Player::draw()
{
}

void Player::collide()
{
    canMove = false;
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

void Player::move()
{
    acc = Math::clamp(0, maxAcc, pow(acc, 2));
    speed = Math::clamp(0, maxSpeed, speed + acc);
    x += speed;
    y += speed;

    QFrame::move(x, y);
}
