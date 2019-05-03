#ifndef MAPFILES_H
#define MAPFILES_H

#include <QString>
#include <QFile>
#include <QDebug>


class MapFiles
{
public:
    static QList<QList<QChar>> read(QString path);
};

#endif // MAPFILES_H
