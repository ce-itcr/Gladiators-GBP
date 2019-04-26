#ifndef GRID_H
#define GRID_H

#include <QFrame>

#include "tile.h"
#include "graph/map.h"

class Grid : public QFrame
{
    Q_OBJECT
public:
    explicit Grid(QWidget *parent = nullptr);

signals:

public slots:

private:
    Map *map;
    QList<Tile *> tiles;

    void loadGrid();
};

#endif // GRID_H
