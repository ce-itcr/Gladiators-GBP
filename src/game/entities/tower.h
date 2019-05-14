#ifndef TOWER_H
#define TOWER_H

#include <QString>

#include <json/jsonserializable.h>


class Tower : public JsonSerializable
{
public:
    Tower();

    Tower(QString id,
    int damagePerShoot,
    int attackSpeed,
    int xp,
    int type,
    int level,
    int baseAttackSpeed,
    int baseDamagePerShoot,
    int xpForLevelUp,
    int i,
    int j);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

    QString getId() const;
    void setId(const QString &value);

    int getDamagePerShoot() const;
    void setDamagePerShoot(int value);

    int getAttackSpeed() const;
    void setAttackSpeed(int value);

    int getXp() const;
    void setXp(int value);

    int getType() const;
    void setType(int value);

    int getLevel() const;
    void setLevel(int value);

    int getBaseAttackSpeed() const;
    void setBaseAttackSpeed(int value);

    int getXpForLevelUp() const;
    void setXpForLevelUp(int value);

    int getI() const;
    void setI(int value);

    int getJ() const;
    void setJ(int value);

private:
    QString id;
    int damagePerShoot;
    int attackSpeed;
    int xp;
    int type;
    int level;
    int baseAttackSpeed;
    int baseDamagePerShoot;
    int xpForLevelUp;
    int i;
    int j;
};

#endif // TOWER_H
