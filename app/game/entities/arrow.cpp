#include "arrow.h"
#include "game/entities/player.h"

Arrow::Arrow(QWidget *parent, int x, int y) : QFrame(parent)
{
    tag = "arrow";
    this->x = x;
    this->y = y;
    width = 13;
    height = 13;
    damage = 1;
    xSpeed = 0;
    ySpeed = 0;
    xAcc = 1;
    yAcc = 1;
    maxSpeed = 60;
    maxAcc = 10;
    target = nullptr;

//    this->setStyleSheet("background-color:#EBF5EE;");

    setStyleSheet("background-color:#635255;"
                  "image: url(:/img/fire/00fire.png)");
    this->setGeometry(x, y, width, height);
    this->show();
}

void Arrow::update()
{
    if (target != nullptr) move();
}

void Arrow::draw()
{

}

void Arrow::collide()
{
    for (Entity *entity : GameController::getInstance()->getEntities())
    {
        if (entity->tag == "player" &&
                Collision::collide(getRect(), entity->getRect()))
        {
            GameController::getInstance()->removeEntity(this);
            delete this;
            break;
        }
    }
}

void Arrow::uncollide()
{

}

QRect Arrow::getRect()
{
    QRect rect(x, y, width, height);
    return rect;
}

int Arrow::getX() const
{
    return x;
}

void Arrow::setX(int value)
{
    x = value;
}

int Arrow::getY() const
{
    return y;
}

void Arrow::setY(int value)
{
    y = value;
}

Entity *Arrow::getTarget() const
{
    return target;
}

void Arrow::setTarget(Entity *value)
{
    target = value;
}

void Arrow::move()
{
    if (target->tag != "player") return;

        int offset = 10;
        Player *targetPlayer = static_cast<Player *>(target);
        xSpeed = Math::clamp(0, maxSpeed, xSpeed + xAcc);
        ySpeed = Math::clamp(0, maxSpeed, ySpeed + yAcc);
        x = Math::approach(x, targetPlayer->getX() + offset, xSpeed);
        y = Math::approach(y, targetPlayer->getY() + offset, ySpeed);;

        QFrame::move(x, y);
}
