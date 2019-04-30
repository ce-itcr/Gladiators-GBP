#include "math.h"

int Math::clamp(int min, int max, int num)
{
    int result = num;
    if (num < min) result = min;
    if (num > max) result = max;
    return result;
}
