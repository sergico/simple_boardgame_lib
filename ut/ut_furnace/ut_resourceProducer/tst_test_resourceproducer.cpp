#include <QtTest>

// add necessary includes here

class Test_ResourceProducer : public QObject
{
    Q_OBJECT

public:
    Test_ResourceProducer();
    ~Test_ResourceProducer();

private slots:
    void test_case1();

};

Test_ResourceProducer::Test_ResourceProducer()
{

}

Test_ResourceProducer::~Test_ResourceProducer()
{

}

void Test_ResourceProducer::test_case1()
{

}

QTEST_APPLESS_MAIN(Test_ResourceProducer)

#include "tst_test_resourceproducer.moc"
