#ifndef ENEMY_H
#define ENEMY_H

#include <QFrame>
#include <QDebug>
#include <QTime>

#include "entity.h"
#include "game/entities/tower.h"
#include "game/entities/arrow.h"
#include "util/math.h"

class Enemy : public QFrame, public Entity
{
    Q_OBJECT
public:
    Enemy(QWidget *parent = nullptr, int x = 0, int y = 0);

    ~Enemy();

    void update();

    void draw();

    void collide();

    void collide(QList<Entity *> players);

    void uncollide();

    QRect getRect();

    QRegion getCircle();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    Tower *getTower() const;
    void setTower(Tower *value);

private:
    Tower *tower;
    int x;
    int y;
    int width;
    int height;
    Entity *target;
    int range;
    QTime shootDelay;
    bool canShoot;

    Entity *closerPlayer(QList<Entity *> players);

    void shoot(Entity *entity);
};

#endif // ENEMY_H
