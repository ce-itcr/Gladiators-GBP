#include "gamecontroller.h"
#include "spawner.h"

GameController *GameController::instance = new GameController();

GameController *GameController::getInstance()
{
    return instance;
}

void GameController::run()
{
    update(); // Starts the loop

}

void GameController::stop()
{
    cycleTime = 25;
    waveActive = false;
    pause = false;
    entities.clear();
}

void GameController::addEntity(Entity *entity)
{
    entities.push_back(entity);
    addedEntity(entity);
}

void GameController::removeEntity(Entity *entity)
{
    toDeleteEntities.push_back(entity);
    if (entity->tag == "player") alertArrows(entity);
}

void GameController::callWave()
{
    for (Entity *entity : entities)
    {
        if (entity->tag == "enemy") removeEntity(entity);
    }
    QList<Gladiator> gladiators = populations->getGladiatorsValues();
    QList<Tower> towers = populations->getTowersValues();
    populations->sendPopulation(gladiators, towers);
    QTimer::singleShot(2000, populations, &Populations::updatePopulation);
}

void GameController::update()
{
    QTimer::singleShot(cycleTime, this, &GameController::update);
    if (pause) return;

    if (waveActive) checkWave();

    int size = entities.size();
    for (int i = 0; i < size; i++)
    {
        Entity *entity = entities.value(i);
        if (entity)
        {
            entity->update();
            entity->draw();
            entity->collide();
        }
    }
    deleteEntities();
}

void GameController::populationReady()
{
    waveWaiting = false;
}

QString GameController::getMap() const
{
    return map;
}

void GameController::setMap(const QString &value)
{
    map = value;
}

bool GameController::getWaveWaiting() const
{
    return waveWaiting;
}

void GameController::setWaveWaiting(bool value)
{
    waveWaiting = value;
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
    populations = Populations::getInstance();
    cycleTime = 25;
    waveActive = false;
    waveWaiting = false;
    pause = false;
    map = "://maps/snake";

    QObject::connect(populations, &Populations::readyPopulation,
                     this, &GameController::populationReady);
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

void GameController::checkWave()
{
    bool hasPlayers = false;
    if (!Spawner::getInstance()->isWaveFinished()) hasPlayers = true;
    for (Entity *player : entities)
    {
        if (player->tag == "player")
        {
            hasPlayers = true;
            break;
        }
    }
    if (!waveWaiting && !hasPlayers) {
        callWave();
        waveWaiting = true;
        waveActive = false;
    }
}

void GameController::deleteEntities()
{
    for (Entity *entity : toDeleteEntities)
    {
        entities.removeOne(entity);
        try {
            delete entity;
            entity = nullptr;
        } catch (...) { }
    }
    toDeleteEntities.clear();
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

void GameController::alertArrows(Entity *player)
{
    for (Entity *entity : entities)
    {
        if (entity->tag == "arrow")
        {
            Arrow *arrow = dynamic_cast<Arrow *>(entity);
            if (arrow->getTarget() == player)
                arrow->setTarget(nullptr);
        }
    }
}
