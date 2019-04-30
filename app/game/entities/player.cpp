#include "player.h"

Player::Player(QWidget *parent) : QFrame (parent)
{
    x = 0;
    y = 0;
    speed = 0;
    acc = 1;
    maxSpeed = 10;
    maxAcc = 2;

    this->setStyleSheet("background-color:green;");
    this->setGeometry(x, y, 50, 50);
    this->show();
}

void Player::update()
{
    acc = Math::clamp(0, maxAcc, pow(acc, 2));
    speed = Math::clamp(0, maxSpeed, speed + acc);
    x += speed;
    y += speed;

    this->move(x, y);
}

void Player::draw()
{
}
