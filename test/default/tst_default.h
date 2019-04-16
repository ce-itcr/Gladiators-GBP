#ifndef TST_DEFAULT_H
#define TST_DEFAULT_H

#include <QtTest>

class Default : public QObject
{
    Q_OBJECT

public:
    Default();
    ~Default();

private slots:
    void test_case1();

};

#endif // TST_DEFAULT_H
