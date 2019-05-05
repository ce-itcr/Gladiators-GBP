#ifndef ARROW_H
#define ARROW_H

#include "entity.h"
#include "util/math.h"

#include <QFrame>

class Arrow : public QFrame, public Entity
{
    Q_OBJECT
public:
    explicit Arrow(QWidget *parent = nullptr);

    ~Arrow() = default;

    // Entity interface
    void update();
    void draw();
    void collide();
    void uncollide();
    QRect getRect();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    Entity *getTarget() const;
    void setTarget(Entity *value);

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

    void move();
};

#endif // ARROW_H
