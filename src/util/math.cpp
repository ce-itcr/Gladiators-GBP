#include "math.h"

int Math::clamp(int min, int max, int num)
{
    int result = num;
    if (num < min) result = min;
    if (num > max) result = max;
    return result;
}

int Math::approach(int num, int target, int amount)
{
    if (num < target)
    {
        num += amount;
        if (num > target)
            return target;
    }
    else
    {
        num -= amount;
        if (num < target)
            return target;
    }
    return num;
}

int Math::distance(int x1, int y1, int x2, int y2)
{
    int x = (x2 - x1);
    int y = (y2 - y1);
    int distance = sqrt(pow(x, 2) + pow(y, 2));
    return distance;
}
