#include "clientinterface.h"

Client *ClientInterface::client = Client::getInstance();
Populations *ClientInterface::populations = Populations::getInstance();

void ClientInterface::postPopulations()
{
    client->POST("/populations", "");
}

void ClientInterface::getGladiators()
{
    client->GET("/populations/gladiators");
    QObject::connect(client, &Client::readyRead,
                     populations, &Populations::updateGladiators);
}

void ClientInterface::postGladiators(QString jsonGladiators)
{
    client->POST("/populations/gladiators/stats", jsonGladiators);
}

void ClientInterface::getTowers()
{
    client->GET("/populations/towers");
    QObject::connect(client, &Client::readyRead,
                     populations, &Populations::updateTowers);
}

void ClientInterface::postTowers(QString jsonTowers)
{
    client->POST("/populations/towers/stats", jsonTowers);
}
