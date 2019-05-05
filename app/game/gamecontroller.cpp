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
    entities.push_back(entity);
}

void GameController::removeEntity(Entity *entity)
{
    entities.removeOne(entity);
}

void GameController::update()
{
    QTimer::singleShot(cycleTime, this, &GameController::update);
    if (pause) return;

    for (Entity *entity : entities)
    {
        collision(entity);
        entity->update();
        entity->draw();
    }
}

QList<Entity *> GameController::getEntities() const
{
    return entities;
}

void GameController::setEntities(const QList<Entity *> &value)
{
    entities = value;
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

GameController::GameController()
{
    cycleTime = 25;
    waveActive = false;
    pause = false;
}

void GameController::collision(Entity *entity)
{
    QList<Entity *> colliders = entities;
    colliders.removeOne(entity);
    colliders = playersInEntities(colliders);

    if (entity->tag == "enemy") {
        Enemy *enemy = dynamic_cast<Enemy *>(entity);
        QList<Entity *> players = playersInRangeOfTower(enemy->getCircle(), colliders);
        enemy->collide(players);
    }
    if (entity->tag == "arrow") {
        Arrow *arrow = dynamic_cast<Arrow *>(entity);
        bool hit = playerHit(arrow->getRect(), colliders);
        if (hit) arrow->collide();

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

QList<Entity *> GameController::playersInRangeOfTower(QRegion region, QList<Entity *> entities)
{
    QList<Entity *> players;
    for (Entity *player : entities)
    {
        if (Collision::collide(region, player->getRect())) players.push_back(player);
    }
    return players;
}

bool GameController::playerHit(QRect arrowRect, QList<Entity *> entities)
{
    bool collision = false;
    for (Entity *player : entities)
    {
        if (Collision::collide(arrowRect, player->getRect()))
        {
            collision = true;
            break;
        }
    }
    return collision;
}
