#ifndef POPULATIONS_H
#define POPULATIONS_H

#include "gladiator.h"
#include "tower.h"

#include <QObject>

class Populations : public QObject
{
    Q_OBJECT
public:
    static Populations *getInstance();

    void startNewPopulation();

    void sendPopulation(QList<Gladiator> newGladiators, QList<Tower> newTowers);

    QList<Gladiator> *getGladiators() const;
    void setGladiators(QList<Gladiator> *value);

    QList<Tower> *getTowers() const;
    void setTowers(QList<Tower> *value);

signals:

public slots:
    void updateGladiators(QString *);

    void updateTowers(QString *);

private:
    static Populations *instance;
    QList<Gladiator> *gladiators;
    QList<Tower> *towers;

    Populations();
};

#endif // POPULATIONS_H
