#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>

#include "entities/entity.h"

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

signals:

public slots:
    void update();

private:
    static GameController *instance;
    QList<Entity *> *entities;
    int cycleTime;

    GameController();
};

#endif // GAMECONTROLLER_H
