#ifndef TOWER_H
#define TOWER_H

#include <QString>

#include <json/jsonserializable.h>


class Tower : public JsonSerializable
{
public:
    Tower();

    Tower(QString id, int fireRate);

    QString getId() const;
    void setId(const QString &value);

    int getFireRate() const;
    void setFireRate(int value);

    int getI() const;
    void setI(int value);

    int getJ() const;
    void setJ(int value);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

private:
    QString id;
    int fireRate;
    int i;
    int j;
};

#endif // TOWER_H
