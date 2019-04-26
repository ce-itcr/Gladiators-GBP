#ifndef TILE_H
#define TILE_H

#include <QFrame>
#include "graph/node.h"

class Tile : public QFrame
{
    Q_OBJECT
public:
    Tile(QWidget *parent = nullptr, int i = 0, int j = 0);

    int getI() const;

    int getJ() const;

signals:

public slots:

private:
    int i;
    int j;
    Node *node;
};

#endif // TILE_H
