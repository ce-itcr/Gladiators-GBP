#include "tower.h"

Tower::Tower()
{
    this->id = "";
}

Tower::Tower(QString id)
{
    this->id = id;
}

QString Tower::getId() const
{
    return id;
}

void Tower::setId(const QString &value)
{
    id = value;
}
