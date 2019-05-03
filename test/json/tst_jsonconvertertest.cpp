#include "tst_jsonconvertertest.h"

JsonConverterTest::JsonConverterTest()
{

}

JsonConverterTest::~JsonConverterTest()
{

}

void JsonConverterTest::test_gladiatorsToJson()
{
    QList<Gladiator> gladiators;
    Gladiator g1("1", "Spartacus", "21");
    Gladiator g2("2", "Aquiles", "23");
    gladiators.push_back(g1);
    gladiators.push_back(g2);

    // Serialize
    QString json = JsonConverter::gladiatorsToJson(gladiators);

    // Parse
    QList<Gladiator *> *parsedGladiators = JsonConverter::jsonToGladiators(json);

    QCOMPARE(parsedGladiators->size(), 2);
    QCOMPARE(parsedGladiators->value(0)->getName(), g1.getName());
    QCOMPARE(parsedGladiators->value(1)->getName(), g2.getName());
}

void JsonConverterTest::test_towersToJson()
{
    QList<Tower> towers;
    Tower t1("1");
    Tower t2("2");
    towers.push_back(t1);
    towers.push_back(t2);

    // Serialize
    QString json = JsonConverter::towersToJson(towers);

    // Parse
    QList<Tower *> *parsedTowers = JsonConverter::jsonToTowers(json);

    QCOMPARE(parsedTowers->size(), 2);
    QCOMPARE(parsedTowers->value(0)->getId(), t1.getId());
    QCOMPARE(parsedTowers->value(1)->getId(), t2.getId());
}
