#ifndef GRID_H
#define GRID_H

#include <QFrame>

#include "tile.h"
#include "graph/map.h"
#include "game/entities/enemy.h"
#include "game/gamecontroller.h"
#include "game/spawner.h"

class Grid : public QFrame
{
    Q_OBJECT
public:
    explicit Grid(QWidget *parent = nullptr);

    void load();

    QList<Tile *> getTiles() const;
    void setTiles(const QList<Tile *> &value);

    int getTileSize() const;

signals:

public slots:
    void on_waveButton_clicked();

// QWidget interface
protected:
    void resizeEvent(QResizeEvent *);

    void mousePressEvent(QMouseEvent *event);

private:
    Map *map;
    GameController *gameController;
    Spawner *spawner;
    QList<Tile *> tiles;
    int rows;
    int columns;
    int offset = 1;
    int tileSize;

    void loadGrid();

    void updateGrid();

    void createEntity(Tile *tile);
};

#endif // GRID_H
