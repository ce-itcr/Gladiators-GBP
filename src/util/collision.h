#ifndef COLLISION_H
#define COLLISION_H

#include <QRect>
#include <QList>

class Collision
{
public:
    static bool collide(QRect rect1, QRect rect2);

    static bool collide(QRect rect, QList<QRect> rects);

    static bool collide(QRegion region, QRect rect);
};

#endif // COLLISION_H
