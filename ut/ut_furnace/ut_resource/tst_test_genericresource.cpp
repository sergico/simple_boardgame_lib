#include <QtTest>

// add necessary includes here
#include "resource.h"

class Test_GenericResource : public QObject
{
    Q_OBJECT

public:
    Test_GenericResource();
    ~Test_GenericResource();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_case1();

};

void Test_GenericResource::initTestCase()
{

}

void Test_GenericResource::cleanupTestCase()
{

}

Test_GenericResource::Test_GenericResource()
{

}

Test_GenericResource::~Test_GenericResource()
{

}

void Test_GenericResource::test_case1()
{

}

QTEST_APPLESS_MAIN(Test_GenericResource)

#include "tst_test_genericresource.moc"
