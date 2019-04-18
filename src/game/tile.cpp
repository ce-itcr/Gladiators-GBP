#include "tile.h"

Tile::Tile()
{
    entity = nullptr;
    occupied = false;
}

Entity *Tile::getEntity() const
{
    return entity;
}

void Tile::setEntity(Entity *value)
{
    entity = value;
}

bool Tile::isOccupied() const
{
    return occupied;
}

void Tile::setOccupied(bool value)
{
    occupied = value;
}
