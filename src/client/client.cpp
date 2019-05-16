#include "client.h"

Client *Client::instance = new Client();

Client *Client::getInstance()
{
    return instance;
}

void Client::GET(const QString &path)
{
    QUrl url(Client::path + path);
    QNetworkRequest request(url);

    qDebug() << "Client GET request to: " << url.toString();
    manager->get(request);

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::POST(const QString &path, const QString &data)
{
    QUrl url(Client::path + path);
    QNetworkRequest request(url);
    request.setRawHeader("Content-Type", "application/json");

    qDebug() << "Client POST request to: " << url.toString();
    manager->post(request, data.toUtf8());

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &Client::replyFinished);
}

void Client::loadHost(QString ip, QString port)
{
    path = "http://" + ip + ":" + port + defaultPath;
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
    ip = "localhost";
    port = "9080";
    defaultPath = "/Gladiators_Server_war_exploded";
    path = "http://localhost:9080/Gladiators_Server_war_exploded";
}
