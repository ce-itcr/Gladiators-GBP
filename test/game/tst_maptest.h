#ifndef TST_MAPTEST_H
#define TST_MAPTEST_H

#include <QTest>
#include "graph/map.h"

class MapTest : public QObject
{
    Q_OBJECT
public:
    MapTest();
    ~MapTest();

private slots:
    void test_resize();
    void test_tileAt();
    void test_indexOfTile();
};

#endif // TST_MAPTEST_H
