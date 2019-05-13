#ifndef GRID_H
#define GRID_H

#include <QFrame>
#include <QPainter>
#include <QMediaPlayer>

#include "tile.h"
#include "graph/map.h"
#include "graph/mapfiles.h"
#include "game/entities/enemy.h"
#include "game/gamecontroller.h"
#include "game/populations.h"
#include "game/spawner.h"
#include "graph/PathFinding/findpath.h"

class Grid : public QFrame
{
    Q_OBJECT
public:
    Grid(QWidget *parent = nullptr, QString mapFilePath = "://maps/map1");

    void load();

    Tile *tileAt(int i, int j);

    QList<Tile *> getTiles() const;
    void setTiles(const QList<Tile *> &value);

    int getTileSize() const;

signals:

public slots:

// QWidget interface
protected:
    void resizeEvent(QResizeEvent *);

    void mousePressEvent(QMouseEvent *event);

private:
    Map *map;
    GameController *gameController;
    Populations *populations;
    Spawner *spawner;
    QList<Tile *> tiles;
    QList<QList<QChar>> mapFile;
    int rows;
    int columns;
    int offset = 1;
    int tileSize;

    void loadGrid();

    void loadTileSettings(Tile *tile, int i, int j);

    void updateGrid();

    void createEntity(Tile *tile);

    void drawCircle(Entity *entity);
};

#endif // GRID_H
