#include "grid.h"

Grid::Grid(QWidget *parent) : QFrame(parent)
{
    map = Map::getInstance();
}
