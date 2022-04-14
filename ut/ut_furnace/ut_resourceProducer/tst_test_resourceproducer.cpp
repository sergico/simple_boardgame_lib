#include <QtTest>

// add necessary includes here
#include "resourceProducer.h"
#include "furnaceResources.h"
#include <QList>

class Test_ResourceProducer : public QObject
{
    Q_OBJECT

    QList<sgl::ResourcesProducer> m_resourcesProducerList;

public:
    Test_ResourceProducer();
    ~Test_ResourceProducer();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void test_produceSingleResource();
    void test_produceResourcesInRange();
    void test_produceResourcesOutOfRange();

};

Test_ResourceProducer::Test_ResourceProducer()
{}

Test_ResourceProducer::~Test_ResourceProducer()
{}

void Test_ResourceProducer::initTestCase()
{

}

void Test_ResourceProducer::cleanupTestCase()
{

}

void Test_ResourceProducer::init()
{
    furnace::Coal* coalPtr = new furnace::Coal;
    QSharedPointer<sgl::GenericResource> coalShPtr(coalPtr);
    sgl::ResourcesProducer coalProducer( coalShPtr );
    m_resourcesProducerList.append(coalProducer);

    furnace::OilBarrel* oilBarrelPtr = new furnace::OilBarrel;
    sgl::GenericResourceShPtr oilBarrelShPtr(oilBarrelPtr);
    sgl::ResourcesProducer oilBarrelProducer( oilBarrelShPtr );
    m_resourcesProducerList.append(oilBarrelProducer);

}

void Test_ResourceProducer::cleanup()
{
    m_resourcesProducerList.clear();
}

void Test_ResourceProducer::test_produceSingleResource()
{
    foreach(sgl::ResourcesProducer theResourceProducer, m_resourcesProducerList)
    {
        theResourceProducer.produce();
        QVERIFY(theResourceProducer.resource()->value() == 1);
    }
}

void Test_ResourceProducer::test_produceResourcesInRange()
{
    foreach(sgl::ResourcesProducer theResourceProducer, m_resourcesProducerList)
    {
        for(int i = 0; i < furnace::MAX_RESOURCE_VALUE; i++)
        {
            theResourceProducer.produce();
            QVERIFY(theResourceProducer.resource()->value() == i+1);
        }
    }
}

void Test_ResourceProducer::test_produceResourcesOutOfRange()
{
    foreach(sgl::ResourcesProducer theResourceProducer, m_resourcesProducerList)
    {
        for(int i = 0; i < furnace::MAX_RESOURCE_VALUE; i++)
        {
            theResourceProducer.produce();
            QVERIFY(theResourceProducer.resource()->value() == i+1);
        }
        QVERIFY_EXCEPTION_THROWN( theResourceProducer.produce(), sgl::resource::ValueOutOfRange );
    }
}

QTEST_APPLESS_MAIN(Test_ResourceProducer)

#include "tst_test_resourceproducer.moc"
