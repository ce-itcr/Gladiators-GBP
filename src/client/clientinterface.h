#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "client.h"
#include "game/populations.h"

class ClientInterface
{
public:
    static void postPopulations();

    static void getGladiators();

    static void postGladiators(QString jsonGladiators);

    static void getTowers();

    static void postTowers(QString jsonTowers);

private:
    static Client *client;
    static Populations *populations;

};

#endif // CLIENTINTERFACE_H
