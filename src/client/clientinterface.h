#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "client.h"

#include <entities/gladiator.h>
#include <entities/tower.h>


class ClientInterface
{
public:
    QList<Gladiator> getGladiators();

    void postGladiators(QList<Gladiator> gladiators);

    QList<Tower> getTowers();

    void postTowers(QList<Tower> towers);

private:
    static Client *client;
};

#endif // CLIENTINTERFACE_H
