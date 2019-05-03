#ifndef MATH_H
#define MATH_H


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
};

#endif // MATH_H
