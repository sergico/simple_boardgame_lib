#include <QtTest>

// add necessary includes here

#include "resourceView.h"
#include "resource.h"

class Test_ResourceView : public QObject
{
    Q_OBJECT

public:
    Test_ResourceView();
    ~Test_ResourceView();

private slots:
    void test_case1();

};

Test_ResourceView::Test_ResourceView()
{

}

Test_ResourceView::~Test_ResourceView()
{

}

void Test_ResourceView::test_case1()
{
    sgl::GenericResourceShPtr testResourcePtr(new sgl::GenericResource(
                                                  sgl::Range<int>(0, 10),
                                                  2,
                                                  "test resource"));
    sgl::ResourceViewTerminal theResourceView(testResourcePtr);
    theResourceView.draw();
}

QTEST_APPLESS_MAIN(Test_ResourceView)

#include "tst_test_resourceview.moc"
