#include "spawner.h"

#include "game/entities/player.h"
#include "game/entities/enemy.h"

Spawner *Spawner::instance = nullptr;

Spawner *Spawner::getInstance(QObject *parent)
{
    if (instance == nullptr) instance = new Spawner(parent);
    return instance;
}

void Spawner::spawnGladiators(QList<Gladiator *> *value)
{
    gladiators = value;
    gameController->setWaveActive(true);
    spawn();
}

void Spawner::spawnTower(Tile *tile, Tower *tower)
{
    Grid *grid = dynamic_cast<Grid *>(parent);
    int tileSize = grid->getTileSize();

    Enemy *enemy = new Enemy(grid);
    enemy->setX(tile->x());
    enemy->setY(tile->y());
    enemy->resize(tileSize, tileSize);
    enemy->setTower(tower);

    Entity *entity = enemy;
    gameController->addEntity(entity);
    tile->getNode()->setEntity(entity);
}

void Spawner::spawnArrow(int x, int y, Entity *target)
{
    Grid *grid = dynamic_cast<Grid *>(parent);

    Arrow *arrow = new Arrow(grid);
    arrow->setTarget(target);
    arrow->setX(x);
    arrow->setY(y);

    Entity *entity = arrow;
    gameController->addEntity(entity);
}

bool Spawner::isWaveFinished()
{
    return gladiators->isEmpty();
}

void Spawner::spawn()
{
    if (gladiators->isEmpty()) return;

    // Generates the player
    Grid *grid = dynamic_cast<Grid *>(parent);
    Player *player = new Player(grid);
    Gladiator *gladiator = gladiators->takeFirst();
    player->setGladiator(gladiator);
    player->setNodePath(gladiator->getNodePath());
    int size = grid->getTileSize();
    player->resize(size, size);

    Entity *entity = player;
    gameController->addEntity(entity);

    // Recursive call
    QTimer::singleShot(spawnDelay, this, &Spawner::spawn);
}

void Spawner::setParent(QObject *value)
{
    parent = value;
}

Spawner::Spawner(QObject *parent) : QObject (parent), parent(parent)
{
    gameController = GameController::getInstance();
    spawnDelay = 1000;
}
