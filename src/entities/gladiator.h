#ifndef GLADIATOR_H
#define GLADIATOR_H

#include <QString>


class Gladiator
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

private:
    QString id;
    QString name;
    QString age;
};

#endif // GLADIATOR_H
