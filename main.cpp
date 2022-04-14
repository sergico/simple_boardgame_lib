#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QMap>

#include "resource.h"
#include "furnaceResources.h"
#include "resourceView.h"
#include "resourceConverter.h"
#include "resourceProducer.h"
#include "furnaceResourceConverters.h"

void printResources(const QList<sgl::GenericResourceShPtr> resources)
{
    foreach(sgl::GenericResourceShPtr resourcePtr, resources) {
        qDebug() << resourcePtr->toString();
    }
}

void testGenericResource()
{
    sgl::Range<int> defaultRange(0, 1000);
    sgl::GenericResourceShPtr coalPtr( new sgl::GenericResource(defaultRange, 0, "coal") );
    sgl::GenericResourceShPtr ironBarPtr( new sgl::GenericResource(defaultRange, 0, "iron bar") );
    sgl::GenericResourceShPtr oilBarrelPtr( new sgl::GenericResource(defaultRange, 0, "oil barrel") );

    QList<sgl::GenericResourceShPtr> resourceList;
    resourceList.append(coalPtr);
    resourceList.append(ironBarPtr);
    resourceList.append(oilBarrelPtr);

    printResources(resourceList);
    (*coalPtr)++;
    (*ironBarPtr)++;
    (*oilBarrelPtr)++;
    printResources(resourceList);
}

void testFurnaceResources()
{
    qDebug() << "----------------------------------------";
    sgl::GenericResourceShPtr coalPtr( new furnace::Coal );
    sgl::GenericResourceShPtr ironBarPtr( new furnace::IronBar );
    sgl::GenericResourceShPtr oilBarrelPtr( new furnace::OilBarrel );
    sgl::GenericResourceShPtr cogPtr( new furnace::Cog );

    QList<sgl::GenericResourceShPtr> resourceList;
    resourceList.append(coalPtr);
    resourceList.append(ironBarPtr);
    resourceList.append(oilBarrelPtr);

    printResources(resourceList);
    (*coalPtr)++;
    (*ironBarPtr)++;
    (*oilBarrelPtr)++;
    printResources(resourceList);
}


void testResourceConverter()
{
    qDebug() << "----------------------------------------";
    qDebug() << "==== [test resource converter] ====";

    furnace::Coal coal;
    furnace::IronBar ironBar;

    coal.value(5);
    ironBar.value(1);


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testGenericResource();
    testFurnaceResources();

    testResourceConverter();


    return 0;
    //return a.exec();
}
