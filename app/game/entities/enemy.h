#ifndef ENEMY_H
#define ENEMY_H

#include <QFrame>
#include <QDebug>
#include <QTime>
#include <QPushButton>

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

    void updateDelta();

    QRect getRect();

    void playerKill();

    QRegion getCircle();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    Tower *getTower() const;
    void setTower(Tower *value);

    static int getBuildCost();
    static void setBuildCost(int value);

    static int getOnKillMoney();
    static void setOnKillMoney(int value);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);

    void resizeEvent(QResizeEvent *);

private slots:
    void boost();

    void endBoost();

private:
    Tower *tower;
    int x;
    int y;
    int width;
    int height;
    Entity *target;
    int range;
    QTime shootDelay;
    int fireRate;
    int damageSaved;
    int attackSpeedSaved;
    float deltaTime = 66;
    bool canShoot;
    static int buildCost;
    static int onKillMoney;
    static int boostCost;
    static int boostTime;
    static int boostRate;

    Entity *closerPlayer(QList<Entity *> players);

    void shoot(Entity *entity);

    void updateShootDelay();
};

#endif // ENEMY_H
