#include "map.h"

Map *Map::instance = new Map();

Map *Map::getInstance()
{
    return instance;
}

void Map::reSizeMatrix(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;

    delete matrix;
    matrix = new QList<QList<Tile *> *>();
    loadMatrix();
}

void Map::clearMatrix()
{
    reSizeMatrix(rows, columns);
}

Tile *Map::tileAt(int row, int column)
{
    QList<Tile *> *columns = matrix->value(row);
    Tile *tile = columns->value(column);
    return tile;
}

QPair<int, int> Map::indexOf(Tile *tile)
{
    bool finished = false;
    QPair<int, int> index;
    for (int i = 0; i < rows; i++) {
        QList<Tile*> *column = matrix->value(i);
        for (int j = 0; j < columns; j++) {
            Tile *tmp = column->value(j);
            if (tmp == tile)
            {
                index = qMakePair(i, j);
                finished = true;
                break;
            }
        }
        if (finished) break;
    }
    return index;
}

Map::Map()
{
    rows = 10;
    columns = 10;
    loadMatrix();
}

void Map::loadMatrix()
{
    matrix = new QList<QList<Tile *> *>();
    for (int i = 0; i < rows; i++) {
        QList<Tile*> *row = new  QList<Tile *>();
        matrix->push_back(row);

        for (int j = 0; j < columns; j++) {
            row->push_back(new Tile());
        }
    }
}
