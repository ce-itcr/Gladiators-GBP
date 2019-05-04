#include "grid.h"

Grid::Grid(QWidget *parent) : QFrame(parent)
{
    map = Map::getInstance();
    gameController = GameController::getInstance();
    spawner = Spawner::getInstance(this);
    rows = map->getRows();
    columns = map->getColumns();
    mapFile = MapFiles::read("://maps/map1");

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

void Grid::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    for (Tile *tile : tiles)
    {
        if (tile->getRect().contains(x, y)) createEntity(tile);
    }
}

int Grid::getTileSize() const
{
    return tileSize;
}

QList<Tile *> Grid::getTiles() const
{
    return tiles;
}

void Grid::setTiles(const QList<Tile *> &value)
{
    tiles = value;
}

void Grid::loadGrid()
{
    int x = offset, y = offset;
    int width = (this->width() - offset * columns) / columns;
    int height = (this->height() - offset * rows) / rows;
    tileSize = (width + height) / 2;

    for(int i = 0; i < rows; i++)
    {
        y = height * i + offset * i + 1;
        for (int j = 0; j < columns; j++) {
            x = width * j + offset * j + 1;

            Node *node = map->nodeAt(i, j);
            node->setX(x);
            node->setY(y);

            Tile *tile = new Tile(this, i, j);
            tile->setNode(node);
            tile->setGeometry(x, y, width, height);
            tile->show();
            tiles.push_back(tile);

            loadTileSettings(tile, i, j);
        }
        x = offset;
    }
}

void Grid::loadTileSettings(Tile *tile, int i, int j)
{
    QChar qchar = mapFile[i][j];
    tile->setup(qchar);
}

void Grid::updateGrid()
{
    int x = offset, y = offset;
    int i, j;
    int width = (this->width() - offset * columns) / columns;
    int height = (this->height() - offset * rows) / rows;
    tileSize = (width + height) / 2;
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

void Grid::createEntity(Tile *tile)
{
    if (!tile->canBuild()) return;

    Enemy *enemy = new Enemy(this);
    enemy->setX(tile->x());
    enemy->setY(tile->y());
    enemy->resize(tileSize, tileSize);
    gameController->addEntity(enemy);

    tile->getNode()->setEntity(enemy);
}

