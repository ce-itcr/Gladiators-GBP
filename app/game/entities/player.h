#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "util/math.h"
#include "cmath"

#include <QFrame>
#include <QDebug>

class Player : public QFrame, public Entity
{
    Q_OBJECT
public:
    Player(QWidget *parent = nullptr);

    void update();

    void draw();

    void collide();

    void uncollide();

    QRect getRect();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int x;
    int y;
    int width;
    int height;
    int speed;
    int acc;

    int maxSpeed;
    int maxAcc;
    bool canMove;

    void move();
};

#endif // PLAYER_H
