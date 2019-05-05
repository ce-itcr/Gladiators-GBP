#ifndef ENEMY_H
#define ENEMY_H

#include <QFrame>
#include <QDebug>
#include "entity.h"
#include "game/entities/tower.h"
#include "util/math.h"

class Enemy : public QFrame, public Entity
{
    Q_OBJECT
public:
    explicit Enemy(QWidget *parent = nullptr);

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

    Entity *closerPlayer(QList<Entity *> players);
};

#endif // ENEMY_H
