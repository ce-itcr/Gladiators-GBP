#include "jsonserializer.h"

QJsonObject JsonSerializer::serialize(const JsonSerializable &obj)
{
    QJsonObject jsonObj;
    obj.write(jsonObj);
    return jsonObj;
}

void JsonSerializer::parse(const QString &json, JsonSerializable &jsonSerializable)
{
    QJsonDocument document = QJsonDocument::fromJson(json.toUtf8());

    // The document wrap a jsonObject
    QJsonObject jsonObj = document.object();

    jsonSerializable.read(jsonObj);
}
