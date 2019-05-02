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
        QList<QRect> colliders = rectsOfEntities();
        if (Collision::collide(entity->getRect(), colliders)) entity->collide();
        else entity->uncollide();

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
    pause = false;
}

QList<QRect> GameController::rectsOfEntities()
{
    QList<QRect> rects;
    for (Entity *entity : *entities)
    {
        if (entity->tag != "player")
        {
            rects.push_back(entity->getRect());
        }
    }
    return rects;
}
