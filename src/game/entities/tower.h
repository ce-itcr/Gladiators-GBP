#ifndef TOWER_H
#define TOWER_H

#include <QString>

#include <json/jsonserializable.h>


class Tower : public JsonSerializable
{
public:
    Tower();

    Tower(QString id);

    QString getId() const;
    void setId(const QString &value);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

private:
    QString id;
};

#endif // TOWER_H
