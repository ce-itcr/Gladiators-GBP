#include "mapfiles.h"

QList<QList<QChar>> MapFiles::read(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Fail to open file: " << path
                 << " ERROR :" << file.errorString();
    }

    QTextStream in(&file);
    QList<QList<QChar>> matrix;

    int i = 0;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QList<QChar> row;

        for (QChar qchar : line) row.push_back(qchar);
        matrix.push_back(row);

        i++;
    }

    file.close();
    return matrix;
}
