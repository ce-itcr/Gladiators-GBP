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

    void addMoney(int extra);

    void spendMoney(int expended);

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

    bool getWaveWaiting() const;
    void setWaveWaiting(bool value);

    QString getMap() const;
    void setMap(const QString &value);

    int getMoney() const;
    void setMoney(int value);

    int getLife() const;
    void setLife(int value);

    int getWave() const;
    void setWave(int value);

    int getStartingLife() const;
    void setStartingLife(int value);

signals:
    void addedEntity(Entity *entity);

public slots:
    void update();

    void populationReady();

private:
    static GameController *instance;
    Populations *populations;
    QList<Entity *> entities;
    QList<Entity *> entitiesStack;
    QList<Entity *> toDeleteEntities;
    int cycleTime;
    bool waveActive;
    bool waveWaiting;
    bool pause;
    QString map;
    int money;
    int startingLife;
    int life;
    int wave;
    int startingMoney;

    GameController();

    void collision(Entity *entity);

    void checkWave();

    void deleteEntities();

    QList<Entity *> playersInRangeOfTower(QRegion region);

    bool playerHit(QRect arrowRect);

    void alertArrows(Entity *entity);

    void clearEntitiesStack();
};

#endif // GAMECONTROLLER_H
