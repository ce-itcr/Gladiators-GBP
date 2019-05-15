#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

#include "entities/entity.h"
#include "util/collision.h"
#include "game/entities/enemy.h"
#include "game/entities/arrow.h"
#include "game/populations.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    static GameController *getInstance();

    void run();

    void stop();

    void addEntity(Entity *entity);

    void removeEntity(Entity *entity);

    void callWave();

    bool isWaveActive() const;
    void setWaveActive(bool value);

    bool isPause() const;
    void setPause(bool value);

    int getCycleTime() const;
    void setCycleTime(int value);

    QList<Entity *> getEntities() const;
    void setEntities(const QList<Entity *> &value);

signals:
    void addedEntity(Entity *entity);

public slots:
    void update();

private:
    static GameController *instance;
    Populations *populations;
    QList<Entity *> entities;
    QList<Entity *> toDeleteEntities;
    int cycleTime;
    bool waveActive;
    bool pause;

    GameController();

    void collision(Entity *entity);

    void checkWave();

    void deleteEntities();

    QList<Entity *> playersInRangeOfTower(QRegion region);

    bool playerHit(QRect arrowRect);
};

#endif // GAMECONTROLLER_H
