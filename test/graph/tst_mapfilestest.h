#ifndef TST_MAPFILESTEST_H
#define TST_MAPFILESTEST_H

#include <QTest>
#include "graph/mapfiles.h"

class MapFilesTest : public QObject
{
    Q_OBJECT
public:
    MapFilesTest();
    ~MapFilesTest();

private slots:
    void test_read();
};

#endif // TST_MAPFILESTEST_H
