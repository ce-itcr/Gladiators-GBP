#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QTimer>

#include "game/entities/entity.h"
#include "game/gamecontroller.h"
#include "game/entities/gladiator.h"


class Spawner : public QObject
{
    Q_OBJECT
public:
    static Spawner *getInstance(QObject *parent = nullptr);

    void spawnGladiators(QList<Gladiator *> gladiators);

    bool isWaveFinished();

public slots:
    void spawn();

private:
    static Spawner *instance;
    GameController *gameController;
    QList<Gladiator *> gladiators;
    int spawnDelay;

    Spawner(QObject *parent);
};

#endif // SPAWNER_H
