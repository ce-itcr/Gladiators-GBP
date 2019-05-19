#include "grid.h"

#include "game/entities/player.h"

Grid::Grid(QWidget *parent, QString mapFilePath) : QFrame(parent)
{
    map = Map::getInstance();
    gameController = GameController::getInstance();
    populations = Populations::getInstance();
    spawner = Spawner::getInstance();
    spawner->setParent(this);
    rows = map->getRows();
    columns = map->getColumns();
    focusable = true;
    mapFile = MapFiles::read(mapFilePath);

    this->setStyleSheet("background-color: #EBF5EE;");
}

void Grid::load()
{
    loadGrid();
}

Tile *Grid::tileAt(int i, int j)
{
    Tile *result = nullptr;
    for (Tile *tile :tiles)
    {
        if (tile->getI() == i && tile->getJ() == j) result = tile;
    }
    return result;
}

void Grid::resizeEvent(QResizeEvent *)
{
    updateGrid();
}

void Grid::mousePressEvent(QMouseEvent *event)
{
    if (!focusable) return;
    int x = event->x();
    int y = event->y();

    buildTower(x, y);
}

bool Grid::isFocusable() const
{
    return focusable;
}

void Grid::setFocusable(bool value)
{
    focusable = value;
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

void Grid::buildTower(int x, int y)
{
    int buildCost = Enemy::getBuildCost();
    int money = gameController->getMoney();
    if (money < buildCost) return;

    FindPath::instance->pathCost = 10000;
    for (Tile *tile : tiles)
    {
        // Buildable tile
        if (tile->getRect().contains(x, y) && tile->canBuild())
        {
            tile->getNode()->setOccupied(true);
            FindPath::instance->shortestPath();

            // Pathfinder check for another path
            if(FindPath::instance->pathCost != 10000)
            {
                createEntity(tile);

                QMediaPlayer* genWave = new QMediaPlayer;
                genWave->setMedia(QUrl("qrc:/audio/hammering.wav"));
                genWave->setVolume(100);
                genWave->play();

            } else tile->getNode()->setOccupied(false);
        }
    }
}

void Grid::createEntity(Tile *tile)
{
    int buildCost = Enemy::getBuildCost();
    QList<Tower *> *towers = populations->getTowers();
    QString id = QString::number(towers->size());
    Tower *tower = new Tower();
    tower->setId(id);
    tower->setI(tile->getI());
    tower->setJ(tile->getJ());
    spawner->spawnTower(tile, tower);
    towers->push_back(tower);
    gameController->spendMoney(buildCost);

    updatePaths();
}

void Grid::updatePaths()
{
    for (Entity *entity : gameController->getEntities())
    {
        if (entity->tag == "player")
        {
            Player *player = dynamic_cast<Player *>(entity);
            player->updatePath();
        }
    }
}
