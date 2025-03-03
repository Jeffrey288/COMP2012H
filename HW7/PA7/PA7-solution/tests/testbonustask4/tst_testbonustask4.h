#ifndef TESTBONUSTASK4_H
#define TESTBONUSTASK4_H

#include <QtTest>

class TestBonusTask4 : public QObject
{
    Q_OBJECT

private:
    QSet<QString> dummyAnswers {};

public:
    TestBonusTask4();
    ~TestBonusTask4() = default;

private slots:
    void testComputeEntropy_data();
    void testComputeEntropy();

    void testSolverHint();

    void testSolverHintWithUpdate1();
    void testSolverHintWithUpdate2();
    void testSolverHintWithUpdate3();
};

#endif // TESTBONUSTASK4_H
