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
    loadMatrix();
}

void Map::clearMatrix()
{
    reSizeMatrix(rows, columns);
}

Node *Map::tileAt(int row, int column)
{
    QList<Node *> *columns = matrix->value(row);
    Node *tile = columns->value(column);
    return tile;
}

QPair<int, int> Map::indexOf(Node *tile)
{
    bool finished = false;
    QPair<int, int> index;
    for (int i = 0; i < rows; i++) {
        QList<Node*> *column = matrix->value(i);
        for (int j = 0; j < columns; j++) {
            Node *tmp = column->value(j);
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

QList<QList<Node *> *> *Map::getMatrix() const
{
    return matrix;
}

void Map::setMatrix(QList<QList<Node *> *> *value)
{
    matrix = value;
}

int Map::getRows() const
{
    return rows;
}

int Map::getColumns() const
{
    return columns;
}

Map::Map()
{
    rows = 15;
    columns = 15;
    loadMatrix();
}

void Map::loadMatrix()
{
    matrix = new QList<QList<Node *> *>();
    for (int i = 0; i < rows; i++) {
        QList<Node*> *row = new  QList<Node *>();
        matrix->push_back(row);

        for (int j = 0; j < columns; j++) {
            row->push_back(new Node());
        }
    }
}
