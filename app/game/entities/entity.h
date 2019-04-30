#ifndef ENTITY_H
#define ENTITY_H

#include <QList>

class Entity
{
public:
    QString tag = "";

    virtual ~Entity() {}

    virtual void update() = 0;

    virtual void draw() = 0;

    virtual void collide() = 0;

    virtual void uncollide() = 0;

    virtual QRect getRect() = 0;
};

#endif // ENTITY_H
