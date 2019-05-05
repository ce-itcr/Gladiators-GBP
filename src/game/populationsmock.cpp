#include "populationsmock.h"

Populations *PopulationsMock::populations = Populations::getInstance();
QString *PopulationsMock::gladiators = new QString();
QString *PopulationsMock::towers = new QString();
int PopulationsMock::gladiatorsCount = 10;

void PopulationsMock::run()
{
    loadJsons();
    loadPopulations();
}

void PopulationsMock::loadNoadesPath(QList<Node *> nodesPath)
{
    for (Gladiator *gladiator : *populations->getGladiators())
    {
        gladiator->setNodePath(nodesPath);
    }
}

void PopulationsMock::loadPopulations()
{
    populations->updateGladiators(gladiators);
    populations->updateTowers(towers);
}

void PopulationsMock::loadJsons()
{
    QList<Gladiator> newGladitors;
    for (int i = 0; i < gladiatorsCount; i++) {
        Gladiator gladiator;
        newGladitors.push_back(gladiator);
    }
    QList<Tower> newTowers;
    Tower tower("1", 1000);
    tower.setI(12);
    tower.setJ(12);
    newTowers.push_back(tower);

    gladiators = new QString(JsonConverter::gladiatorsToJson(newGladitors));
    towers = new QString(JsonConverter::towersToJson(newTowers));
}
