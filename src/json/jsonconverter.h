#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <QList>
#include <QString>
#include <QJsonArray>
#include <QDebug>

#include "game/entities/gladiator.h"
#include "game/entities/tower.h"
#include "jsonserializer.h"


class JsonConverter
{
public:
    static QString gladiatorsToJson(QList<Gladiator> gladiators);

    static QString towersToJson(QList<Tower> towers);

    static QList<Gladiator *> *jsonToGladiators(QString jsonGladiators);

    static QList<Tower *> *jsonToTowers(QString jsonTowers);

private:
    static QJsonObject stringToJsonObject(const QString& data);

    static QJsonArray stringToJsonArray(const QString& data);
};

#endif // JSONCONVERTER_H
