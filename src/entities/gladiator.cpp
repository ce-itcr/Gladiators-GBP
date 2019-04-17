#include "gladiator.h"

Gladiator::Gladiator()
{
    this->id = "";
    this->name = "";
    this->age = "";
}

Gladiator::Gladiator(QString id, QString name, QString age)
{
    this->id = id;
    this->name = name;
    this->age = age;
}

QString Gladiator::getId() const
{
    return id;
}

void Gladiator::setId(const QString &value)
{
    id = value;
}

QString Gladiator::getName() const
{
    return name;
}

void Gladiator::setName(const QString &value)
{
    name = value;
}

QString Gladiator::getAge() const
{
    return age;
}

void Gladiator::setAge(const QString &value)
{
    age = value;
}

void Gladiator::write(QJsonObject &jsonObj) const
{
    jsonObj["id"] = id;
    jsonObj["name"] = name;
    jsonObj["age"] = age;
}

void Gladiator::read(const QJsonObject &jsonObj)
{
    id = jsonObj["id"].toString();
    name = jsonObj["name"].toString();
    age = jsonObj["age"].toString();
}
