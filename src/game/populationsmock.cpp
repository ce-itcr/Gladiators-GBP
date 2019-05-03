#include "populationsmock.h"

Populations *PopulationsMock::populations = Populations::getInstance();
QString *PopulationsMock::gladiators = new QString();
QString *PopulationsMock::towers = new QString();

void PopulationsMock::run()
{
    loadPopulations();
}

void PopulationsMock::loadPopulations()
{
    for (int i = 0; i < 20; i++) {
        populations->updateGladiators(gladiators);
        populations->updateTowers(towers);
    }
}

void PopulationsMock::loadJsons()
{
    gladiators = new QString("");
    towers = new QString("");
}
