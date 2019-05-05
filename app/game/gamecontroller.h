#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

#include "entities/entity.h"
#include "util/collision.h"
#include "game/entities/enemy.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    static GameController *getInstance();

    void run();

    void addEntity(Entity *entity);

    void removeEntity(Entity *entity);

    QList<Entity *> *getEntities() const;
    void setEntities(QList<Entity *> *value);

    bool isWaveActive() const;
    void setWaveActive(bool value);

    bool isPause() const;
    void setPause(bool value);

    int getCycleTime() const;
    void setCycleTime(int value);

signals:

public slots:
    void update();

private:
    static GameController *instance;
    QList<Entity *> *entities;
    int cycleTime;
    bool waveActive;
    bool pause;

    GameController();

    void collision(Entity *entity);

    QList<Entity *> playersInEntities(QList<Entity *> entities);

    QList<Entity *> playersInRange(QRegion region, QList<Entity *> entities);
};

#endif // GAMECONTROLLER_H
