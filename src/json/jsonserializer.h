#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "json/jsonserializable.h"
#include <QJsonDocument>

class JsonSerializer
{
public:
    static QString serialize(const JsonSerializable &obj);

    static void parse(const QString &json, JsonSerializable &jsonSerializable);
};

#endif // ERIALIZER_H
