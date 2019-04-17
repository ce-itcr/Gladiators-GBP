#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <QList>
#include <QString>
#include <QJsonArray>

#include "game/entities/gladiator.h"
#include "game/entities/tower.h"
#include "jsonserializer.h"


class JsonConverter
{
public:
    static QString GladiatorsToJson(QList<Gladiator> gladiators);

    static QString TowersToJson(QList<Tower> towers);
};

#endif // JSONCONVERTER_H
