#include "tst_maptest.h"

MapTest::MapTest()
{

}

MapTest::~MapTest()
{

}

void MapTest::test_resize()
{
    Map *map = Map::getInstance();
    auto *matrix = map->getMatrix();

    QCOMPARE(matrix->size(), 15);
    QCOMPARE(matrix->value(0)->size(), 15);

    map->reSizeMatrix(10, 10);
    QCOMPARE(matrix->size(), 10);
    QCOMPARE(matrix->value(0)->size(), 10);
}

void MapTest::test_tileAt()
{
    Map *map = Map::getInstance();
    Node *tile = map->tileAt(1, 1);

    QVERIFY(!tile->isOccupied());
    tile->setOccupied(true);

    Node *newTile = map->tileAt(1, 1);
    QVERIFY(newTile->isOccupied());
}

void MapTest::test_indexOfTile()
{
    Map *map = Map::getInstance();
    Node *tile = map->tileAt(1, 2);

    QPair<int, int> index = map->indexOf(tile);

    QCOMPARE(index.first, 1);
    QCOMPARE(index.second, 2);
}
