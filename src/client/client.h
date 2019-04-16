#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class Client : public QObject
{
    Q_OBJECT
public:
    static Client *getInstance();

    void GET(const QString &path);

    void POST(const QString &path, const QString &data);

signals:
    void readyRead(QString *);

public slots:
    void replyFinished(QNetworkReply *);

private:
    static Client *instance;
    QNetworkAccessManager *manager;
    QString defaultPath;

    Client();
};

#endif // CLIENT_H
