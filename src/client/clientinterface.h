#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "client.h"

class ClientInterface
{
public:
    void postPopulations();

    void getGladiators();

    void postGladiators(QString jsonGladiators);

    void getTowers();

    void postTowers(QString jsonTowers);

private:
    static Client *client;
};

#endif // CLIENTINTERFACE_H
