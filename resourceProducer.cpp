#include "resourceProducer.h"


void sgl::ResourcesProducer::produceImpl()
{
    (*resource())++;
    //resource()->increment(m_resourceToProduce);
}

void sgl::ResourcesProducer::produceImpl(int i_resourcesToProduce)
{
    resource()->increment(i_resourcesToProduce);
}
