#include "grid.h"

Grid::Grid(QWidget *parent) : QFrame(parent)
{
    map = Map::getInstance();
    gameController = GameController::getInstance();
    spawner = Spawner::getInstance(this);
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

void Grid::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    for (Tile *tile : tiles)
    {
        if (tile->getRect().contains(x, y)) createEntity(tile);
    }
}

QList<Tile *> Grid::getTiles() const
{
    return tiles;
}

void Grid::setTiles(const QList<Tile *> &value)
{
    tiles = value;
}

void Grid::on_waveButton_clicked()
{
    // Loads a path
    QList<Node *> nodes;
    for (Tile *tile : tiles)
    {
        nodes.push_back(tile->getNode());
    }

    QList<Gladiator *> gladiators;
    for (int i = 0; i < 10; i++) {
        Gladiator *gladiator = new Gladiator();
        gladiator->setNodePath(nodes);
        gladiators.push_back(gladiator);
    }

    spawner->spawnGladiators(gladiators);
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

void Grid::createEntity(Tile *tile)
{
    Node *node = tile->getNode();
    if (node->isOccupied()) return;

    Enemy *enemy = new Enemy(this);
    enemy->setX(tile->x());
    enemy->setY(tile->y());
    gameController->addEntity(enemy);

    node->setEntity(enemy);
    node->setOccupied(true);
}

