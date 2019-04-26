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
    Node *tile = map->nodeAt(1, 1);

    QVERIFY(!tile->isOccupied());
    tile->setOccupied(true);

    Node *newTile = map->nodeAt(1, 1);
    QVERIFY(newTile->isOccupied());
}

void MapTest::test_indexOfTile()
{
    Map *map = Map::getInstance();
    Node *tile = map->nodeAt(1, 2);

    QPair<int, int> index = map->indexOf(tile);

    QCOMPARE(index.first, 1);
    QCOMPARE(index.second, 2);

    QCOMPARE(map->nodeAt(-1, -2), nullptr);
    QCOMPARE(map->nodeAt(15, 18), nullptr);
    QCOMPARE(map->nodeAt(10, 4), nullptr);
}

void MapTest::test_neighbors()
{
    Map *map = Map::getInstance();

    Node *node = map->nodeAt(5, 5);
    QCOMPARE(node->getNeighbors()->size(), 8);
    QVERIFY(node->getNeighbors()->contains(map->nodeAt(5, 6)));
    QVERIFY(node->getNeighbors()->contains(map->nodeAt(4, 6)));

    Node *node2 = map->nodeAt(0, 9);
    QCOMPARE(node2->getNeighbors()->size(), 3);
    QVERIFY(node2->getNeighbors()->contains(map->nodeAt(1, 8)));
	QVERIFY(node2->getNeighbors()->contains(map->nodeAt(1, 9)));
	QVERIFY(!node2->getNeighbors()->contains(map->nodeAt(1, 7)));
}
