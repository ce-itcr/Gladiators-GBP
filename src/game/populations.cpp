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

QList<Gladiator> Populations::getGladiatorsValues()
{
    QList<Gladiator> newGladiators;
    for (Gladiator *gladiator : *gladiators)
    {
        newGladiators.push_back(*gladiator);
    }
    return newGladiators;
}

QList<Tower> Populations::getTowersValues()
{
    QList<Tower> newTowers;
    for (Tower *tower : *towers)
    {
        newTowers.push_back(*tower);
    }
    return newTowers;
}

void Populations::updateGladiators(QString jsonGladiators)
{
    qDebug() << "Populations::updateGladiators()";
    QList<Gladiator *> *newGladiators = JsonConverter::jsonToGladiators(jsonGladiators);
    gladiatorsReady = true;
    gladiators = newGladiators;
    populationUpdated();
}

void Populations::updateTowers(QString jsonTowers)
{
    qDebug() << "Populations::updateTowers()";
    QList<Tower *> *newTowers = JsonConverter::jsonToTowers(jsonTowers);
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
