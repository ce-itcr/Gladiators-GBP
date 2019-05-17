#include "tower.h"

Tower::Tower()
{
    this->id = "";
    this->damagePerShoot = 10;
    this->attackSpeed = 1000;
    this->xp = 0;
    this->type = 1;
    this->level = 1;
    this->baseAttackSpeed = 1000;
    this->baseDamagePerShoot = 1;
    this->xpForLevelUp = 20;
    this->i = 0;
    this->j = 0;
}

Tower::Tower(QString id, int damagePerShoot, int attackSpeed, int xp, int type, int level, int baseAttackSpeed, int baseDamagePerShoot, int xpForLevelUp, int i, int j)
{
    this->id = id;
    this->damagePerShoot = damagePerShoot;
    this->attackSpeed = attackSpeed;
    this->xp = xp;
    this->type = type;
    this->level = level;
    this->baseAttackSpeed = baseAttackSpeed;
    this->baseDamagePerShoot = baseDamagePerShoot;
    this->xpForLevelUp = xpForLevelUp;
    this->i = i;
    this->j = j;
}

void Tower::write(QJsonObject &jsonObj) const
{
    jsonObj["id"] = id;
    jsonObj["damagePerShot"] = damagePerShoot;
    jsonObj["attackSpeed"] = attackSpeed;
    jsonObj["xp"] = xp;
    jsonObj["type"] = type;
    jsonObj["level"] = level;
    jsonObj["baseAttackSpeed"] = baseAttackSpeed;
    jsonObj["baseDamagePerShot"] = baseDamagePerShoot;
    jsonObj["xpForLevelUp"] = xpForLevelUp;
    jsonObj["i"] = i;
    jsonObj["j"] = j;
}

void Tower::read(const QJsonObject &jsonObj)
{
    id = jsonObj["id"].toString();
    damagePerShoot = jsonObj["damagePerShot"].toInt();
    attackSpeed = jsonObj["attackSpeed"].toInt();
    xp = jsonObj["xp"].toInt();
    type = jsonObj["type"].toInt();
    level = jsonObj["level"].toInt();
    baseAttackSpeed = jsonObj["baseAttackSpeed"].toInt();
    baseDamagePerShoot = jsonObj["baseDamagePerShot"].toInt();
    xpForLevelUp = jsonObj["xpForLevelUp"].toInt();
    i = jsonObj["i"].toInt();
    j = jsonObj["j"].toInt();
}

QString Tower::getId() const
{
    return id;
}

void Tower::setId(const QString &value)
{
    id = value;
}

int Tower::getDamagePerShoot() const
{
    return damagePerShoot;
}

void Tower::setDamagePerShoot(int value)
{
    damagePerShoot = value;
}

int Tower::getAttackSpeed() const
{
    return attackSpeed;
}

void Tower::setAttackSpeed(int value)
{
    attackSpeed = value;
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

int Tower::getXp() const{
    return xp;
}

void Tower::setXp(int value){
    xp = value;
}

int Tower::getXpForLevelUp() const{
    return xpForLevelUp;
}

void Tower::setXpForLevelUp(int value){
    xpForLevelUp = value;
}

int Tower::getType() const{
    return type;
}

void Tower::setType(int value){
    type = value;
}
