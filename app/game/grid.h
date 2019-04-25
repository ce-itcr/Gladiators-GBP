#ifndef GRID_H
#define GRID_H

#include <QFrame>

#include "game/map.h"
#include "tile.h"

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
};

#endif // GRID_H
