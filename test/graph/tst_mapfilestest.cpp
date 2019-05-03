#include "tst_mapfilestest.h"

MapFilesTest::MapFilesTest()
{

}

MapFilesTest::~MapFilesTest()
{

}

void MapFilesTest::test_read()
{
    QString path = "://maps/map1";
    MapFiles::read(path);
}
