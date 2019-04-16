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

void ClientInterface::postGladiators(QString jsonGladiators)
{
    client->POST("/populations/gladiators/stats", jsonGladiators);
}

void ClientInterface::getTowers()
{
    client->GET("/populations/towers");
}

void ClientInterface::postTowers(QString jsonTowers)
{
    client->POST("/populations/towers/stats", jsonTowers);
}
