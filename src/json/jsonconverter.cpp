#include "jsonconverter.h"


QString JsonConverter::GladiatorsToJson(QList<Gladiator> gladiators)
{
    QJsonArray jsonArray;
    for(Gladiator gladiator : gladiators)
    {
        QJsonValue value = JsonSerializer::serialize(gladiator);
        jsonArray.push_back(value);
    }
    QJsonDocument doc(jsonArray);
    QString data = doc.toJson(QJsonDocument::Compact);
    return data;
}

QString JsonConverter::TowersToJson(QList<Tower> towers)
{
    QJsonArray jsonArray;
    for(Tower tower : towers)
    {
        QJsonValue value = JsonSerializer::serialize(tower);
        jsonArray.push_back(value);
    }
    QJsonDocument doc(jsonArray);
    QString data = doc.toJson(QJsonDocument::Compact);
    return data;
}
