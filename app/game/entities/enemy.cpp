#include "enemy.h"

#include "game/spawner.h"

Enemy::Enemy(QWidget *parent) : QFrame(parent)
{
    tower = nullptr;
    tag = "enemy";
    x = 0;
    y = 0;
    width = 50;
    height = 50;
    target = nullptr;
    shootDelay.start();
    canShoot = false;

    this->setStyleSheet("background-color:blue;");
    this->setGeometry(x, y, width, height);
    this->show();
}

void Enemy::update()
{
    this->move(x, y);
    if (shootDelay.elapsed() >= tower->getFireRate()) canShoot = true;
    collide();
}

void Enemy::draw()
{

}

void Enemy::collide()
{
    QList<Entity *> players;
    for (Entity *entity : GameController::getInstance()->getEntities())
    {
        if (entity->tag == "player" &&
                Collision::collide(getCircle(), entity->getRect()))
        {
            players.push_back(entity);
        }
    }
    collide(players);
}

void Enemy::collide(QList<Entity *> players)
{
    if (players.isEmpty()) target = nullptr;
    else
    {
        target = closerPlayer(players);
        if(canShoot) shoot(target);
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

void Enemy::shoot(Entity *entity)
{
    if (entity == nullptr &&
            entity->tag != "player") return;
    canShoot = false;
    shootDelay.restart();
    Spawner::getInstance()->spawnArrow(x, y, entity);
}
