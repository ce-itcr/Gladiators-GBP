#include "client.h"

Client *Client::instance = new Client();

Client *Client::getInstance()
{
    return instance;
}

void Client::GET(const QString &path)
{
    QUrl url(defaultPath + path);
    QNetworkRequest request(url);

    qDebug() << "Client GET request to: " << url.toString();
    manager->get(request);

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::POST(const QString &path, const QString &data)
{
    QUrl url(defaultPath + path);
    QNetworkRequest request(url);

    qDebug() << "Client POST request to: " << url.toString();
    manager->post(request,  data.toUtf8());

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::replyFinished(QNetworkReply *reply)
{
    QString message = reply->readAll();
    if (message == "") return;

    QString populationType = reply->rawHeader("population-type");
    qDebug() << "Reply finished : " << message;

    if (populationType == "gladiators") readyGladiators(message);
    else if (populationType == "towers") readyTowers(message);
}

Client::Client()
{
    manager = new QNetworkAccessManager();
    defaultPath = "http://localhost:9080/Gladiators_Server_war_exploded";
}
