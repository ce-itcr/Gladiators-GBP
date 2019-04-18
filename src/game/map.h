#ifndef MAP_H
#define MAP_H

#include "tile.h"

#include <QList>


class Map
{
public:
    static Map *getInstance();

    void reSizeMatrix(int rows, int columns);

    void clearMatrix();

    Tile *tileAt(int row, int column);

    QPair<int, int> indexOf(Tile *tile);

    QList<QList<Tile *> *> *getMatrix() const;
    void setMatrix(QList<QList<Tile *> *> *value);

private:
    static Map *instance;
    int rows;
    int columns;
    QList<QList<Tile *> *> *matrix;

    Map();

    void loadMatrix();
};

#endif // MAP_H
