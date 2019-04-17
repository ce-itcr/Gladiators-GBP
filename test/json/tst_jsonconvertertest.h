#ifndef TST_JSONCONVERTERTEST_H
#define TST_JSONCONVERTERTEST_H

#include <QtTest>
#include "json/jsonconverter.h"
#include "game/entities/gladiator.h"
#include "game/entities/tower.h"

class JsonConverterTest : public QObject
{
    Q_OBJECT
public:
    JsonConverterTest();
    ~JsonConverterTest();

private slots:
    void test_gladiatorsToJson();
    void test_towersToJson();
};

#endif // TST_JSONCONVERTERTEST_H
