#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QTimer>

#include "game/entities/entity.h"
#include "game/gamecontroller.h"
#include "game/entities/gladiator.h"
#include "game/entities/tower.h"
#include "game/entities/arrow.h"
#include "game/tile.h"


class Spawner : public QObject
{
    Q_OBJECT
public:
    static Spawner *getInstance(QObject *parent = nullptr);

    void stop();

    void spawnGladiators(QList<Gladiator *> *value);

    void spawnTower(Tile *tile, Tower *tower);

    void spawnArrow(int x, int y, Entity *target);

    bool isWaveFinished();

    void setParent(QObject *value);

    int getSpawnDelay() const;
    void setSpawnDelay(int value);

public slots:
    void spawn();

private:
    static Spawner *instance;
    QObject *parent;
    GameController *gameController;
    QList<Gladiator *> *gladiators;
    int spawnDelay;

    Spawner(QObject *parent);
};

#endif // SPAWNER_H
