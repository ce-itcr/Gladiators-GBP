#include "clientinterface.h"

Client *ClientInterface::client = Client::getInstance();

void ClientInterface::postPopulations()
{
    client->POST("/populations", "");
}

void ClientInterface::getGladiators()
{
    client->GET("/populations/gladiators");
}

void ClientInterface::postGladiators(QList<Gladiator> gladiators)
{
    QString json;
    client->POST("/populations/gladiators/stats", json);
}

void ClientInterface::getTowers()
{
    client->GET("/populations/towers");
}

void ClientInterface::postTowers(QList<Tower> towers)
{
    QString json;
    client->POST("/populations/towers/stats", json);
}
