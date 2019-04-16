#ifndef TOWER_H
#define TOWER_H

#include <QString>


class Tower
{
public:
    Tower();

    Tower(QString id);

    QString getId() const;
    void setId(const QString &value);

private:
    QString id;
};

#endif // TOWER_H
