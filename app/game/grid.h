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

    void load();

    QList<Tile *> getTiles() const;
    void setTiles(const QList<Tile *> &value);

signals:

public slots:

protected:
    void resizeEvent(QResizeEvent *);

private:
    Map *map;
    QList<Tile *> tiles;
    int rows;
    int columns;
    int offset = 1;

    void loadGrid();
    void updateGrid();

    // QWidget interface
};

#endif // GRID_H
