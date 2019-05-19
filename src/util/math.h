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

    /**
     * @brief distance between two points
     * @return an integer
     */
    static int distance(int x1, int y1, int x2, int y2);

    /**
     * @brief random number from cero to range
     * @return an integer
     */
    static int random(int range);

    /**
     * @brief random number from min to max
     * @return an integer
     */
    static int random(int min, int max);
};

#endif // MATH_H
