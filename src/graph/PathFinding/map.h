#ifndef MAP_H
#define MAP_H


class Map
{
public:
    Map(int n);
    int ** map;
    int w, h;
    void updateMap();
    int operator() (int x, int y);
};

#endif // MAP_H
