#include <QtTest>
#include <QSharedPointer>

// add necessary includes here

#include "resource.h"


class Test_GenericResource : public QObject
{
    Q_OBJECT

    QSharedPointer<sgl::GenericResource> m_resourceShPtr;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void cleanup();

    void test_createValidResource();
    void test_createInvalidResource_emptyName();

    void test_createInvalidResource_invalidRange();
    void test_createInvalidResource_invalidInitialValue();

    void test_readResourceValue();
    void test_readResourceInitialValue();
    void test_readResourceName();
    void test_setResourceValue();

    void test_increment();
    void test_decrement();
    void test_operators();

};

void Test_GenericResource::initTestCase() {}

void Test_GenericResource::cleanupTestCase() {}

void Test_GenericResource::cleanup()
{
    m_resourceShPtr.clear();
}

void Test_GenericResource::test_createValidResource()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) );

}

void Test_GenericResource::test_createInvalidResource_emptyName()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "";

    QVERIFY_EXCEPTION_THROWN(m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) ),
                             sgl::resource::EmptyResourceName );
}

void Test_GenericResource::test_createInvalidResource_invalidRange()
{
    int min = 10;
    int max = 0;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    QVERIFY_EXCEPTION_THROWN(m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) ),
                             sgl::range::InvalidRange );
}

void Test_GenericResource::test_createInvalidResource_invalidInitialValue()
{
    int min = 0;
    int max = 10;
    int initialValue = 11;
    const QString resourceName = "oil barrel";

    QVERIFY_EXCEPTION_THROWN( m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) ),
                             sgl::resource::InitialValueOutOfRange );
}

void Test_GenericResource::test_readResourceValue()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) );

    QVERIFY( m_resourceShPtr->value() == initialValue );
}

void Test_GenericResource::test_readResourceInitialValue()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) );

    QVERIFY( m_resourceShPtr->initialValue() == initialValue );
}

void Test_GenericResource::test_readResourceName()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) );

    QVERIFY( m_resourceShPtr->name() == resourceName );
}

void Test_GenericResource::test_setResourceValue()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) );

    int valueToSet = 5;
    m_resourceShPtr->value(valueToSet);
    QVERIFY( m_resourceShPtr->value() == valueToSet );

    valueToSet = max + 1;
    QVERIFY_EXCEPTION_THROWN( m_resourceShPtr->value(valueToSet), sgl::resource::ValueOutOfRange );
}

void Test_GenericResource::test_increment()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) );

    const int step = 1;
    for(int v = initialValue; v < max; v++) {
        int inc = m_resourceShPtr->increment(step);
        QVERIFY(inc == step);
        QVERIFY(m_resourceShPtr->value() == v+1);
    }

    QVERIFY_EXCEPTION_THROWN( m_resourceShPtr->increment(step), sgl::resource::ValueOutOfRange );
}

void Test_GenericResource::test_decrement()
{
    int min = 0;
    int max = 10;
    int initialValue = 10;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) );

    const int step = 1;
    for(int v = initialValue; v > 0; v--) {
        int inc = m_resourceShPtr->decrement(step);
        QVERIFY(inc == -step);
        QVERIFY(m_resourceShPtr->value() == v-1);
    }

    QVERIFY_EXCEPTION_THROWN( m_resourceShPtr->decrement(step), sgl::resource::ValueOutOfRange );
}

void Test_GenericResource::test_operators()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    sgl::GenericResource theResource( sgl::Range<int>(min, max), initialValue, resourceName );
    int value = theResource.value();
    QVERIFY(value == 0);

    theResource++; value++;
    QVERIFY( theResource.value() == value);

    theResource--; value--;
    QVERIFY( theResource.value() == value);
}

QTEST_APPLESS_MAIN(Test_GenericResource)

#include "tst_test_genericresource.moc"
