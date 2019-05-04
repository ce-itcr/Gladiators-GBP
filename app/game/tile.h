#ifndef TILE_H
#define TILE_H

#include <QFrame>
#include "graph/node.h"

class Tile : public QFrame
{
    Q_OBJECT
public:
    Tile(QWidget *parent = nullptr, int i = 0, int j = 0);

    void setup(QChar qchar);

    int getI() const;

    int getJ() const;

    QRect getRect() const;

    Node *getNode() const;
    void setNode(Node *value);

    bool canBuild() const;
    void setCanBuild(bool value);

signals:

public slots:

private:
    int i;
    int j;
    Node *node;
    bool build;
};

#endif // TILE_H
