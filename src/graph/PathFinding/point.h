#ifndef POINT_H
#define POINT_H


class point
{
public:

    int x, y;
    point(int a = 0, int b = 0);
    bool operator ==(const point& o);
    point operator +(const point& o);
};

#endif // POINT_H
