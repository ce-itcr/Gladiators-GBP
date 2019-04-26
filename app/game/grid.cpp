#include "grid.h"

Grid::Grid(QWidget *parent) : QFrame(parent)
{
    map = Map::getInstance();
    this->setStyleSheet("background-color:#EBF5EE;");

    loadGrid();
}

void Grid::loadGrid()
{
    int rows = map->getRows();
    int columns = map->getColumns();
    int offset = 1;
    int x = 0, y = 0;
    int width = (this->width() - offset * columns) / columns;
    int height = (this->height() - offset * rows) / rows;

    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++) {
            Tile *tile = new Tile(this, i, j);
            tile->setGeometry(x, y, width, height);
            tiles.push_back(tile);
        }
    }
}
