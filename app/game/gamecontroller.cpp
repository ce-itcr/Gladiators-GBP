#include "gamecontroller.h"

GameController *GameController::instance = new GameController();

GameController *GameController::getInstance()
{
    return instance;
}

void GameController::run()
{
    update(); // Starts the loop
}

void GameController::addEntity(Entity *entity)
{
    entities->push_back(entity);
}

void GameController::removeEntity(Entity *entity)
{
    entities->removeOne(entity);
}

void GameController::update()
{
    QTimer::singleShot(cycleTime, this, &GameController::update);
    if (pause) return;

    for (Entity *entity : *entities)
    {
        collision(entity);
        entity->update();
        entity->draw();
    }
}

int GameController::getCycleTime() const
{
    return cycleTime;
}

void GameController::setCycleTime(int value)
{
    cycleTime = value;
}

bool GameController::isPause() const
{
    return pause;
}

void GameController::setPause(bool value)
{
    pause = value;
}

bool GameController::isWaveActive() const
{
    return waveActive;
}

void GameController::setWaveActive(bool value)
{
    waveActive = value;
}

QList<Entity *> *GameController::getEntities() const
{
    return entities;
}

void GameController::setEntities(QList<Entity *> *value)
{
    entities = value;
}

GameController::GameController()
{
    entities = new QList<Entity *>();
    cycleTime = 25;
    waveActive = false;
    pause = false;
}

void GameController::collision(Entity *entity)
{
    QList<Entity *> colliders(*entities);
    colliders.removeOne(entity);
    colliders = playersInEntities(colliders);

    if (entity->tag == "enemy") {
        Enemy *enemy = static_cast<Enemy *>(entity);
        QList<Entity *> players = playersInRange(enemy->getCircle(), colliders);
        enemy->collide(players);
    }
    if (entity->tag == "arrow") {

    }
}

QList<Entity *> GameController::playersInEntities(QList<Entity *> entities)
{
    QList<Entity *> players;
    for (Entity *entity : entities)
    {
        if (entity->tag == "player") players.push_back(entity);
    }
    return players;
}

QList<Entity *> GameController::playersInRange(QRegion region, QList<Entity *> entities)
{
    QList<Entity *> players;
    for (Entity *player : entities)
    {
        if (Collision::collide(region, player->getRect())) players.push_back(player);
    }
    return players;
}
