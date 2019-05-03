#include "populationsmock.h"

Populations *PopulationsMock::populations = Populations::getInstance();
QString *PopulationsMock::gladiators = new QString();
QString *PopulationsMock::towers = new QString();

void PopulationsMock::run()
{
    loadJsons();
    loadPopulations();
}

void PopulationsMock::loadPopulations()
{
    populations->updateGladiators(gladiators);
    populations->updateTowers(towers);
}

void PopulationsMock::loadJsons()
{
    QList<Gladiator> newGladitors;
    for (int i = 0; i < 10; i++) {
        Gladiator gladiator;
        newGladitors.push_back(gladiator);
    }

    gladiators = new QString(JsonConverter::gladiatorsToJson(newGladitors));
    towers = new QString("");
}