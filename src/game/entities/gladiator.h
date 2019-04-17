#ifndef GLADIATOR_H
#define GLADIATOR_H

#include <QString>

#include <json/jsonserializable.h>


class Gladiator : public JsonSerializable
{
public:
    Gladiator();

    Gladiator(QString id, QString name, QString age);

    QString getId() const;
    void setId(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getAge() const;
    void setAge(const QString &value);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

private:
    QString id;
    QString name;
    QString age;
};

#endif // GLADIATOR_H
