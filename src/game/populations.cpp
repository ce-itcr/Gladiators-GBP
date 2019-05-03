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
    gladiatorsReady = false;
    towerReady = false;
    ClientInterface::getGladiators();
    ClientInterface::getTowers();
}

void Populations::updateGladiators(QString *jsonGladiators)
{
    qDebug() << "Populations::updateGladiators() " << *jsonGladiators;
    QList<Gladiator *> *newGladiators = JsonConverter::jsonToGladiators(*jsonGladiators);
    gladiatorsReady = true;
    gladiators = newGladiators;
    populationUpdated();
}

void Populations::updateTowers(QString *jsonTowers)
{
    qDebug() << "Populations::updateTowers() " << *jsonTowers;
    QList<Tower *> *newTowers = JsonConverter::jsonToTowers(*jsonTowers);
    towerReady = true;
    towers = newTowers;
    populationUpdated();
}

QList<Tower *> *Populations::getTowers() const
{
    return towers;
}

void Populations::setTowers(QList<Tower *> *value)
{
    towers = value;
}

QList<Gladiator *> *Populations::getGladiators() const
{
    return gladiators;
}

void Populations::setGladiators(QList<Gladiator *> *value)
{
    gladiators = value;
}

Populations::Populations()
{
    gladiators = new QList<Gladiator *>();
    towers = new QList<Tower *>();
    gladiatorsReady = false;
    towerReady = false;
}

void Populations::populationUpdated()
{
    if (gladiatorsReady && towerReady) readyPopulation();
}
