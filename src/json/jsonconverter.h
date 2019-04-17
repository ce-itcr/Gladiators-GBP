#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <QList>
#include <QString>
#include <QJsonArray>

#include "entities/gladiator.h"
#include "entities/tower.h"
#include "jsonserializer.h"


class JsonConverter
{
public:
    static QString GladiatorsToJson(QList<Gladiator> gladiators);

    static QString TowersToJson(QList<Tower> towers);
};

#endif // JSONCONVERTER_H
