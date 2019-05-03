#include "jsonconverter.h"


QString JsonConverter::gladiatorsToJson(QList<Gladiator> gladiators)
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

QString JsonConverter::towersToJson(QList<Tower> towers)
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

QList<Gladiator*> *JsonConverter::jsonToGladiators(QString jsonGladiators)
{
    QList<Gladiator *> *gladiators = new QList<Gladiator *>();
    QJsonArray jsonArray = stringToJsonArray(jsonGladiators);
    for(QJsonValue jsonValue : jsonArray)
    {
        Gladiator *gladiator = new Gladiator();
        JsonSerializer::parse(jsonValue.toString(), *gladiator);
        gladiators->push_back(gladiator);
    }
    return gladiators;
}

QList<Tower *> *JsonConverter::jsonToTowers(QString jsonTowers)
{
    QList<Tower *> *towers = new QList<Tower *>();
    QJsonArray jsonArray = stringToJsonArray(jsonTowers);
    for(QJsonValue jsonValue : jsonArray)
    {
        Tower *tower = new Tower();
        JsonSerializer::parse(jsonValue.toString(), *tower);
        towers->push_back(tower);
    }
    return towers;
}

QJsonObject JsonConverter::stringToJsonObject(const QString& data)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    if(!doc.isNull())
    {
        if(doc.isObject()) obj = doc.object();
        else qDebug() << "Document is not an object";
    }
    else qDebug() << "Invalid JSON...\n" << data;

    return obj;
}

QJsonArray JsonConverter::stringToJsonArray(const QString &data)
{
    QJsonArray array;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    if(!doc.isNull())
    {
        if(doc.isArray()) array = doc.array();
        else qDebug() << "Document is not an object";
    }
    else qDebug() << "Invalid JSON...\n" << data;

    return array;
}
