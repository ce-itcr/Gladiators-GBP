#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "util/math.h"
#include "game/tile.h"
#include "game/grid.h"
#include "graph/node.h"

#include <QFrame>
#include <QDebug>

class Player : public QFrame, public Entity
{
    Q_OBJECT
public:
    Player(QWidget *grid = nullptr);

    void update();

    void draw();

    void collide();

    void uncollide();

    QRect getRect();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    QList<Node *> getNodePath() const;
    void setNodePath(const QList<Node *> &value);

private:
    Grid *grid;
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
