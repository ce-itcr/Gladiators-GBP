#ifndef ARROW_H
#define ARROW_H

#include "entity.h"
#include "util/math.h"
#include "game/entities/tower.h"


#include <QFrame>

class Arrow : public QFrame, public Entity
{
    Q_OBJECT
public:
    Arrow(QWidget *parentEnemy = nullptr, int x = 0, int y = 0);

    ~Arrow();

    // Entity interface
    void update();
    void draw();
    void collide();
    void uncollide();
    QRect getRect();
    QList<Entity *> AOECollide();
    QRegion getCircle();

    void kill();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);
    void setDamage(int Damage);
    int getDamage();
    Entity *getTarget() const;
    void setTarget(Entity *value);

    void setTower(Tower *value);

    Entity *getParent() const;
    void setParent(Entity *value);

private:
    int x;
    int y;
    int width;
    int height;
    int damage;
    int xSpeed;
    int ySpeed;
    int xAcc;
    int yAcc;
    int maxSpeed;
    int maxAcc;
    Entity *target;
    Tower *tower;
    Entity *parentEnemy;

    void move();

    void playerKill();

    void areaDamageEffect();
};

#endif // ARROW_H
