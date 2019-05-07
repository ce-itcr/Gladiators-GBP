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
    load();
}

void Map::clearMatrix()
{
    reSizeMatrix(rows, columns);
}

Node *Map::nodeAt(int row, int column)
{
    Node *tile;

    if (row >= 0 && row < rows
            && column >= 0 && column < columns )
    {
        QList<Node *> *columns = matrix->value(row);
        tile = columns->value(column);
    }
    else tile = nullptr;

    return tile;
}

QPair<int, int> Map::indexOf(Node *node)
{
    bool finished = false;
    QPair<int, int> index;
    for (int i = 0; i < rows; i++) {
        QList<Node*> *column = matrix->value(i);
        for (int j = 0; j < columns; j++) {
            Node *tmp = column->value(j);
            if (tmp == node)
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

QList<Node *> Map::getNodes() const
{
    return nodes;
}

void Map::setNodes(const QList<Node *> &value)
{
    nodes = value;
}

Map::Map()
{
    rows = 15;
    columns = 15;
    load();
}

void Map::load()
{
    loadMatrix();
    loadNeighbors();
}

void Map::loadMatrix()
{
    matrix = new QList<QList<Node *> *>();
    for (int i = 0; i < rows; i++) {
        QList<Node*> *row = new  QList<Node *>();
        matrix->push_back(row);
        for (int j = 0; j < columns; j++) {
            Node *node = new Node();
            node->setX(i);
            node->setY(j);
            row->push_back(node);
            nodes.push_back(node);
        }
    }
}

void Map::loadNeighbors()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Node *node = nodeAt(i, j);
            loadNeighbors(i, j, node);
        }
    }
}

void Map::loadNeighbors(int i, int j, Node *node)
{
    QList<Node *> neighbors;
    neighbors.push_back(nodeAt(i-1, j));
    neighbors.push_back(nodeAt(i, j-1));
    neighbors.push_back(nodeAt(i-1, j-1));
    neighbors.push_back(nodeAt(i+1, j-1));

    for (Node *neighbor : neighbors)
    {
        if (neighbor != nullptr) {
            neighbor->addNeighbor(node);
            node->getNeighbors()->push_back(neighbor);
        }
    }
}
