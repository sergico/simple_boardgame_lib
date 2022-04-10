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
                new sgl::GenericResource(sgl::Range<int>(min, max), initialValue, resourceName) );

}

void Test_GenericResource::test_createInvalidResource_emptyName()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "";


    QVERIFY_EXCEPTION_THROWN(m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) ),
                             sgl::resource::EmptyResourceName);
}

void Test_GenericResource::test_createInvalidResource_invalidRange()
{
    int min = 10;
    int max = 0;
    int initialValue = 0;
    const QString resourceName = "oil barrel";


    QVERIFY_EXCEPTION_THROWN(m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) ),
                             sgl::range::InvalidRange);
}

void Test_GenericResource::test_createInvalidResource_invalidInitialValue()
{
    int min = 0;
    int max = 10;
    int initialValue = 11;
    const QString resourceName = "oil barrel";


    QVERIFY_EXCEPTION_THROWN(m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource( sgl::Range<int>(min, max), initialValue, resourceName ) ),
                             sgl::resource::InitialValueOutOfRange);
}

QTEST_APPLESS_MAIN(Test_GenericResource)

#include "tst_test_genericresource.moc"
