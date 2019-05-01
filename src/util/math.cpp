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
