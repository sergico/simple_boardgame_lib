#ifndef RESOURCEPRODUCER_H
#define RESOURCEPRODUCER_H

#include "resource.h"

namespace sgl {

class ResourceProducerIface
{
    sgl::GenericResourceShPtr m_resource;

    virtual void produceImpl() = 0;
    virtual void produceImpl(int i_resourcesToProduce) = 0;

public:
    ResourceProducerIface(sgl::GenericResourceShPtr& io_resource) :
        m_resource(io_resource)
    {}
    virtual ~ResourceProducerIface() {}

    void produce() { produceImpl(); }
    void produce(int i_resourceToProduce) { produceImpl(i_resourceToProduce); }

    inline sgl::GenericResourceShPtr resource() const { return m_resource; }
};


class ResourcesProducer : public sgl::ResourceProducerIface
{
    void produceImpl();
    void produceImpl(int i_resourcesToProduce);

public:
    ResourcesProducer(sgl::GenericResourceShPtr& io_resource) :
        sgl::ResourceProducerIface(io_resource)
    {}
    virtual ~ResourcesProducer() {}
};

}   // namespace sgl

#endif // RESOURCEPRODUCER_H
