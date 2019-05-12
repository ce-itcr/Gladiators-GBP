#include "clientinterface.h"

Client *ClientInterface::client = Client::getInstance();
Populations *ClientInterface::populations = Populations::getInstance();

void ClientInterface::postPopulations()
{
    QString path = "/populations";
    client->POST(path, "");
}

void ClientInterface::getGladiators()
{
    QString path = "/populations/gladiators";
    client->GET(path);

    QObject::connect(client, &Client::readyGladiators, populations, &Populations::updateGladiators);
}

void ClientInterface::postGladiators(QString jsonGladiators)
{
    QString path = "/populations/gladiators/stats";
    client->POST(path, jsonGladiators);
}

void ClientInterface::getTowers()
{
    QString path = "/populations/towers";
    client->GET(path);

    QObject::connect(client, &Client::readyTowers, populations, &Populations::updateTowers);
}

void ClientInterface::postTowers(QString jsonTowers)
{
    QString path = "/populations/towers/stats";
    client->POST(path, jsonTowers);
}
