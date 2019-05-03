#ifndef POPULATIONS_H
#define POPULATIONS_H

#include "entities/gladiator.h"
#include "entities/tower.h"

#include "json/jsonconverter.h"

#include <QObject>

class Populations : public QObject
{
    Q_OBJECT
public:
    static Populations *getInstance();

    void startNewPopulation();

    void sendPopulation(QList<Gladiator> newGladiators, QList<Tower> newTowers);

    void updatePopulation();

    QList<Gladiator *> *getGladiators() const;
    void setGladiators(QList<Gladiator *> *value);

    QList<Tower *> *getTowers() const;
    void setTowers(QList<Tower *> *value);

signals:
    void readyPopulation();

public slots:
    void updateGladiators(QString *);

    void updateTowers(QString *);

private:
    static Populations *instance;
    QList<Gladiator *> *gladiators;
    QList<Tower *> *towers;
    bool gladiatorsReady;
    bool towerReady;

    Populations();

    void populationUpdated();
};

#endif // POPULATIONS_H
