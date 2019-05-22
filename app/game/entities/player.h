#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "util/math.h"
#include "game/tile.h"
#include "game/grid.h"
#include "graph/node.h"
#include "game/entities/gladiator.h"

#include <QFrame>
#include <QDebug>
#include <util/math.h>

class Player : public QFrame, public Entity
{
    Q_OBJECT
public:
    Player(QWidget *grid = nullptr);

    ~Player();

    void update();

    void draw();

    void collide();

    void uncollide();

    void kill();

    void hit(int damage);

    void freeze(int time);

    void unFreeze();

    void confuse(int time);

    void unConfuse();

    QRect getRect();

    void updatePath();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    QList<Node *> getNodePath() const;
    void setNodePath(const QList<Node *> &value);

    Gladiator *getGladiator() const;
    void setGladiator(Gladiator *value);

signals:
    void gladiatorPressed(Gladiator *);

protected:
    void mousePressEvent(QMouseEvent *);

private:
    Grid *grid;
    Gladiator *gladiator;
    int x;
    int y;
    int width;
    int height;
    int xSpeed;
    int ySpeed;
    int xAcc;
    int yAcc;
    int maxSpeed;
    int maxAcc;
    bool canMove;
    QTime timeAlive;
    QList<Node *> nodePath;
    QList<Tile *> visitedPath;
    Tile *target;
    bool freezed;
    bool confused;

    int getMaxSpeed();

    void move();

    void nextTarget();

    void nextVisitedTarget();

    void miss();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // PLAYER_H
