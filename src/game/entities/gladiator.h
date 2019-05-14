#ifndef GLADIATOR_H
#define GLADIATOR_H

#include <QString>

#include "json/jsonserializable.h"
#include "graph/node.h"


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

    QList<Node *> getNodePath() const;
    void setNodePath(const QList<Node *> &value);

    int getI() const;
    void setI(int value);

    int getJ() const;
    void setJ(int value);


private:
    int i, j;
    QString id;
    QString name;
    QString age;
    QList<Node *> nodePath;
};

#endif // GLADIATOR_H
