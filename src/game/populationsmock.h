#ifndef POPULATIONSMOCK_H
#define POPULATIONSMOCK_H

#include "game/populations.h"
#include "json/jsonconverter.h"

class PopulationsMock
{
public:
    static void run();

    static void loadNoadesPath(QList<Node *> nodesPath);

private:
    static Populations *populations;
    static QString *gladiators;
    static QString *towers;

    static void loadPopulations();

    static void loadJsons();
};

#endif // POPULATIONSMOCK_H
