#ifndef TILE_H
#define TILE_H

#include "game/entities/entity.h"


class Tile
{
public:
    Tile();

    Entity *getEntity() const;
    void setEntity(Entity *value);

    bool isOccupied() const;
    void setOccupied(bool value);

private:
    Entity *entity;
    bool occupied;
};

#endif // TILE_H
