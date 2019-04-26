#include "grid.h"

Grid::Grid(QWidget *parent) : QFrame(parent)
{
    map = Map::getInstance();
    rows = map->getRows();
    columns = map->getColumns();
    this->setStyleSheet("background-color: #EBF5EE;");
}

void Grid::load()
{
    loadGrid();
}

void Grid::resizeEvent(QResizeEvent *)
{
    updateGrid();
}

void Grid::loadGrid()
{
    int x = offset, y = offset;
    int width = (this->width() - offset * columns) / columns;
    int height = (this->height() - offset * rows) / rows;

    for(int i = 0; i < rows; i++)
    {
        y = height * i + offset * i + 1;
        for (int j = 0; j < columns; j++) {
            x = width * j + offset * j + 1;

            Tile *tile = new Tile(this, i, j);
            tile->setNode(map->nodeAt(i, j));
            tile->setGeometry(x, y, width, height);
            tile->show();
            tiles.push_back(tile);
        }
        x = offset;
    }
}

void Grid::updateGrid()
{
    int x = offset, y = offset;
    int i, j;
    int width = (this->width() - offset * columns) / columns;
    int height = (this->height() - offset * rows) / rows;
    for (Tile *tile : tiles)
    {
        i = tile->getI();
        j = tile->getJ();
        x = width * j + offset * j + 1;
        y = height * i + offset * i + 1;
        tile->setGeometry(x, y, width, height);
        tile->update();
    }
}

