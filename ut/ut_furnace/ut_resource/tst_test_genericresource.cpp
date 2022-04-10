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

    void createValidResource();
    void createInvalidResource();
};

void Test_GenericResource::initTestCase() {}

void Test_GenericResource::cleanupTestCase() {}

void Test_GenericResource::cleanup()
{
    m_resourceShPtr.clear();
}

void Test_GenericResource::createValidResource()
{
    int min = 0;
    int max = 10;
    int initialValue = 0;
    const QString resourceName = "oil barrel";

    m_resourceShPtr = QSharedPointer<sgl::GenericResource>(
                new sgl::GenericResource(sgl::Range<int>(min, max), initialValue, resourceName) );

}

void Test_GenericResource::createInvalidResource()
{

}

QTEST_APPLESS_MAIN(Test_GenericResource)

#include "tst_test_genericresource.moc"
