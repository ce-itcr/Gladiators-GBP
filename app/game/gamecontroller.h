#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

#include "entities/entity.h"
#include "util/collision.h"

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

    QList<QRect> rectsOfEntities();
};

#endif // GAMECONTROLLER_H
