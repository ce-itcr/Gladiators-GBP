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

    void loadHost(QString ip, QString port);

signals:
    void readyGladiators(QString );

    void readyTowers(QString );

public slots:
    void replyFinished(QNetworkReply *);

private:
    static Client *instance;
    QNetworkAccessManager *manager;
    QString ip;
    QString port;
    QString path;
    QString defaultPath;

    Client();
};

#endif // CLIENT_H
