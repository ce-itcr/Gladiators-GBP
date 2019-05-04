#include "tower.h"

Tower::Tower()
{
    this->id = "";
}

Tower::Tower(QString id, int fireRate)
{
    this->id = id;
    this->fireRate = fireRate;
    this->i = 0;
    this->j = 0;
}

QString Tower::getId() const
{
    return id;
}

void Tower::setId(const QString &value)
{
    id = value;
}

int Tower::getFireRate() const
{
    return fireRate;
}

void Tower::setFireRate(int value)
{
    fireRate = value;
}

int Tower::getI() const
{
    return i;
}

void Tower::setI(int value)
{
    i = value;
}

int Tower::getJ() const
{
    return j;
}

void Tower::setJ(int value)
{
    j = value;
}

void Tower::write(QJsonObject &jsonObj) const
{
    jsonObj["id"] = id;
    jsonObj["fireRate"] = fireRate;
    jsonObj["i"] = i;
    jsonObj["j"] = j;
}

void Tower::read(const QJsonObject &jsonObj)
{
    id = jsonObj["id"].toString();
    fireRate = jsonObj["fireRate"].toInt();
    i = jsonObj["i"].toInt();
    j = jsonObj["j"].toInt();
}
