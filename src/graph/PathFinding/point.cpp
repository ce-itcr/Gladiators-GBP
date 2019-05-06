#include "point.h"

point::point(int a, int b ) {
    x = a;
    y = b;
}

bool point::operator ==( const point& o ) {
    return o.x == x && o.y == y;
}

point point::operator +( const point& o ) {
    return point( o.x + x, o.y + y );
}
