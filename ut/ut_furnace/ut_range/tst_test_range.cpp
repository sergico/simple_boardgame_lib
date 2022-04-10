#include <QtTest>
#include <QSharedPointer>

// add necessary includes here

#include "range.h"


class Test_Range : public QObject
{
    Q_OBJECT

    QSharedPointer< sgl::Range<int> > m_rangeShPtr;
    int m_min;
    int m_max;

    void createRangeToTest(int i_min, int i_max)
    {
        m_min = i_min;
        m_max = i_max;
        m_rangeShPtr = QSharedPointer< sgl::Range<int> >(new sgl::Range<int>(m_min, m_max));
    }

    void test_rangeLimits()
    {
        QVERIFY(m_rangeShPtr->min() == m_min);
        QVERIFY(m_rangeShPtr->max() == m_max);

        QVERIFY(m_rangeShPtr->contains(m_min));
        QVERIFY(m_rangeShPtr->contains(m_max));

        QVERIFY(!m_rangeShPtr->contains(m_min - 1));
        QVERIFY(!m_rangeShPtr->contains(m_max + 1));

        QVERIFY(m_rangeShPtr->contains(mid(m_min, m_max)));
    }

    inline int mid(int i_min, int i_max) { return (i_min + i_max)/2; }

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_positiveRange();
    void test_negativeRange();
    void test_accrossZeroRange();
    void test_fixedValueResource();
    void test_invalidRange();

};

void Test_Range::initTestCase() {}

void Test_Range::cleanupTestCase() {}



void Test_Range::test_positiveRange()
{
    int min = 0;
    int max = 10;
    createRangeToTest(min, max);
    test_rangeLimits();
}

void Test_Range::test_negativeRange()
{
    int min = -10;
    int max = 0;
    createRangeToTest(min, max);
    test_rangeLimits();
}

void Test_Range::test_accrossZeroRange()
{
    int min = -5;
    int max = 5;
    createRangeToTest(min, max);
    test_rangeLimits();
}

void Test_Range::test_fixedValueResource()
{
    int min = 4;
    int max = 4;
    createRangeToTest(min, max);
    test_rangeLimits();
}

void Test_Range::test_invalidRange()
{
    int min = 10;
    int max = 0;

    /*  Range is invalid because the lower limit is bigger than the upper one */
    QVERIFY_EXCEPTION_THROWN(createRangeToTest(min, max), sgl::range::InvalidRange);
}

QTEST_APPLESS_MAIN(Test_Range)

#include "tst_test_range.moc"
