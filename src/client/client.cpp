#include "client.h"

Client *Client::instance = new Client();

Client *Client::getInstance()
{
    return instance;
}

void Client::GET(const QString &path)
{
    QUrl url(defaultPath.append(path));
    QNetworkRequest request(url);

    qDebug() << "Client GET request to: " << url;
    manager->get(request);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
}

void Client::POST(const QString &path, const QString &data)
{
    QUrl url(defaultPath.append(path));
    QNetworkRequest request(url);

    qDebug() << "Client POST request to: " << url;
    manager->post(request,  data.toUtf8());

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
}

void Client::replyFinished(QNetworkReply *reply)
{
    QString message = reply->readAll();
    qDebug() << "Finished : " << message;
    readyRead(&message);
}

Client::Client()
{
    manager = new QNetworkAccessManager();
    defaultPath = "http://localhost:9080/Gladiators_Server_war_exploded";
}
