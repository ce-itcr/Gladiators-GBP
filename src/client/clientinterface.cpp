#include "clientinterface.h"

Client *ClientInterface::client = Client::getInstance();
Populations *ClientInterface::populations = Populations::getInstance();

void ClientInterface::postPopulations()
{
    QString path = "/populations";
    client->POST(path, "");
    qDebug() << "ClientInterface : POST < " << path;
}

void ClientInterface::getGladiators()
{
    QString path = "/populations/gladiators";
    client->GET(path);
    qDebug() << "ClientInterface : GET < " << path;

    QObject::connect(client, &Client::readyRead,
                     populations, &Populations::updateGladiators);
}

void ClientInterface::postGladiators(QString jsonGladiators)
{
    QString path = "/populations/gladiators/stats";
    client->POST(path, jsonGladiators);
    qDebug() << "ClientInterface : POST < " << path;
}

void ClientInterface::getTowers()
{
    QString path = "/populations/towers";
    client->GET(path);
    qDebug() << "ClientInterface : GET < " << path;

    QObject::connect(client, &Client::readyRead,
                     populations, &Populations::updateTowers);
}

void ClientInterface::postTowers(QString jsonTowers)
{
    QString path = "/populations/towers/stats";
    client->POST(path, jsonTowers);
    qDebug() << "ClientInterface : POST < " << path;
}
