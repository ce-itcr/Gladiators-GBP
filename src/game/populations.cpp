#include "populations.h"
#include "client/clientinterface.h"

Populations *Populations::instance = new Populations();

Populations *Populations::getInstance()
{
    return instance;
}

void Populations::startNewPopulation()
{
    ClientInterface::postPopulations();
}

void Populations::sendPopulation(QList<Gladiator> newGladiators, QList<Tower> newTowers)
{
    QString jsonGladiators = JsonConverter::gladiatorsToJson(newGladiators);
    QString jsonTowers = JsonConverter::towersToJson(newTowers);
    ClientInterface::postGladiators(jsonGladiators);
    ClientInterface::postTowers(jsonTowers);
}

void Populations::updatePopulation()
{
    ClientInterface::getGladiators();
    ClientInterface::getTowers();
}

QList<Gladiator> *Populations::getGladiators() const
{
    return gladiators;
}

void Populations::setGladiators(QList<Gladiator> *value)
{
    gladiators = value;
}

QList<Tower> *Populations::getTowers() const
{
    return towers;
}

void Populations::setTowers(QList<Tower> *value)
{
    towers = value;
}

void Populations::updateGladiators(QString *jsonGladiators)
{
    qDebug() << "Populations::updateGladiators() " << jsonGladiators;
}

void Populations::updateTowers(QString *jsonTowers)
{
    qDebug() << "Populations::updateTowers() " << jsonTowers;
}

Populations::Populations()
{
    gladiators = new QList<Gladiator>();
    towers = new QList<Tower>();
}
