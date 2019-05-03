#include "populationsmock.h"

Populations *PopulationsMock::populations = Populations::getInstance();

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
