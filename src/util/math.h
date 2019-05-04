#ifndef MATH_H
#define MATH_H

#include <cmath>

class Math
{
public:

    /**
     * @brief clamp keeps the num in the interval
     * @return an integer between min and max
     */
    static int clamp(int min, int max, int num);

    /**
     * @brief approach moves "a" towards "b" by "amount"
     * @return an integer
     */
    static int approach(int num, int target, int amount);

    static int distance(int x1, int y1, int x2, int y2);
};

#endif // MATH_H
