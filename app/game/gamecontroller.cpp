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
        entity->update();
        entity->draw();
        //entity->collide();
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
    if (entity->tag == "enemy") {
        Enemy *enemy = dynamic_cast<Enemy *>(entity);
        QList<Entity *> players = playersInRangeOfTower(enemy->getCircle());
        enemy->collide(players);
    }
    if (entity->tag == "arrow") {
        bool hit = playerHit(entity->getRect());
        if (hit) entity->collide();
    }
}

QList<Entity *> GameController::playersInRangeOfTower(QRegion region)
{
    QList<Entity *> players;
    for (Entity *player : entities)
    {
        if (player->tag == "player" &&
                Collision::collide(region, player->getRect()))
        {
            players.push_back(player);
        }
    }
    return players;
}

bool GameController::playerHit(QRect arrowRect)
{
    bool collision = false;
    for (Entity *player : entities)
    {
        if (player->tag == "player" &&
                Collision::collide(arrowRect, player->getRect()))
        {
            collision = true;
            break;
        }
    }
    return collision;
}
