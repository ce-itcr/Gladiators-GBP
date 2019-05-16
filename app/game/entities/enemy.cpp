#include "enemy.h"

#include "game/spawner.h"

Enemy::Enemy(QWidget *parent, int x, int y) : QFrame(parent)
{
    tower = nullptr;
    tag = "enemy";
    this->x = x;
    this->y = y;
    width = 50;
    height = 50;
    range = 2;
    target = nullptr;
    shootDelay.start();
    canShoot = false;

//    this->setStyleSheet("background-color:blue;");
    setStyleSheet("background-color:#635255;"
                  "image: url(:img/tower1.png)");
    this->setGeometry(x, y, width, height);
    this->show();
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    this->move(x, y);
    if (shootDelay.elapsed() >= tower->getAttackSpeed()) canShoot = true;
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
    int xPoss = x - width * range;
    int yPoss = y - height * range;
    int diameter = width * range * 2 + width;
    QRegion circle(xPoss, yPoss, diameter, diameter, QRegion::Ellipse);
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

    int xPoss = x + width / 4;
    int yPoss = y + width / 4;
    Spawner::getInstance()->spawnArrow(xPoss, yPoss, entity, this->tower->damagePerShoot);
}
