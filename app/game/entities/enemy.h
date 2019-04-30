#ifndef ENEMY_H
#define ENEMY_H

#include <QFrame>
#include "entity.h"

class Enemy : public QFrame, public Entity
{
    Q_OBJECT
public:
    explicit Enemy(QWidget *parent = nullptr);

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
};

#endif // ENEMY_H
