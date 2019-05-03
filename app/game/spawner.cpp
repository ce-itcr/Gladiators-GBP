#include "spawner.h"

#include <game/entities/player.h>

#include <game.h>

Spawner *Spawner::instance = nullptr;

Spawner *Spawner::getInstance(QObject *parent)
{
    if (instance == nullptr) instance = new Spawner(parent);
    return instance;
}

void Spawner::spawnGladiators()
{
    gameController->setWaveActive(true);
    spawn();
}

bool Spawner::isWaveFinished()
{
    return gladiators->isEmpty();
}

void Spawner::spawn()
{
    if (gladiators->isEmpty()) return;

    // Generates the player
    Grid *grid = static_cast<Grid *>(parent());
    Entity *entity = new Player(grid);
    Gladiator *gladiator = gladiators->first();
    Player *player = static_cast<Player *>(entity);
    player->setGladiator(gladiator);
    player->setNodePath(gladiator->getNodePath());
    gameController->addEntity(player);

    int size = grid->getTileSize();
    player->resize(size, size);

    // Recursive call
    gladiators->removeFirst();
    QTimer::singleShot(spawnDelay, this, &Spawner::spawn);
}

void Spawner::setGladiators(QList<Gladiator *> *value)
{
    gladiators = value;
}

Spawner::Spawner(QObject *parent) : QObject (parent)
{
    gameController = GameController::getInstance();
    spawnDelay = 1000;
}
