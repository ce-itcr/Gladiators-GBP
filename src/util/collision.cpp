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
        if (rect != rect2) result = rect.intersects(rect2);
        if (result) break;
    }
    return result;
}
