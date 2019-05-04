#include "collision.h"

bool Collision::collide(QRect rect1, QRect rect2)
{
    return rect1.contains(rect2);
}

bool Collision::collide(QRect rect, QList<QRect> rects)
{
    bool result = false;
    for (QRect rect2 : rects)
    {
        result = rect.intersects(rect2);
        if (result) break;
    }
    return result;
}

bool Collision::collide(QRegion region, QRect rect)
{
    return region.intersects(rect);
}

