#include "spawner.h"

#include <game/entities/player.h>

Spawner *Spawner::instance = nullptr;

Spawner *Spawner::getInstance(QObject *parent)
{
    if (instance == nullptr) instance = new Spawner(parent);
    return instance;
}

void Spawner::spawnGladiators(QList<Gladiator *> gladiators)
{
    this->gladiators = gladiators;
    spawn();
}

void Spawner::spawn()
{
    if (gladiators.isEmpty()) return;

    // Generates the player
    Grid *grid = static_cast<Grid *>(parent());
    Entity *entity = new Player(grid);
    Gladiator *gladiator = gladiators.first();
    Player *player = static_cast<Player *>(entity);
    player->setGladiator(gladiator);
    player->setNodePath(gladiator->getNodePath());
    gameController->addEntity(player);

    // Recursive call
    gladiators.removeFirst();
    QTimer::singleShot(spawnDelay, this, &Spawner::spawn);
}

Spawner::Spawner(QObject *parent) : QObject (parent)
{
    gameController = GameController::getInstance();
    spawnDelay = 2000;
}
