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

    for (Entity *entity : *entities)
    {
        QList<QRect> colliders = rectsOfEntities();
        if (Collision::collide(entity->getRect(), colliders)) entity->collide();
        else entity->uncollide();

        entity->update();
        entity->draw();
    }
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
