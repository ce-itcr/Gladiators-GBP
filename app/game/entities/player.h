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

    QRect getRect();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    QList<Node *> getNodePath() const;
    void setNodePath(const QList<Node *> &value);

    Gladiator *getGladiator() const;
    void setGladiator(Gladiator *value);

    int getNodeIndex() const;
    void setNodeIndex(int value);

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
    QList<Node *> nodePath;
    int nodeIndex;
    Tile *target;

    void move();

    void nextTarget();
};

#endif // PLAYER_H
