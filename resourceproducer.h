#ifndef RESOURCEPRODUCER_H
#define RESOURCEPRODUCER_H

namespace sgl {

template<class In>
class ResourceProducerIface
{
    In& m_in;

    virtual void convertImpl() = 0;

public:
    ResourceProducerIface(In& io_in) :
        m_in(io_in)
    {}
    virtual ~ResourceProducerIface() {}

    void convert() { convertImpl(); }

    inline In& in() const { return m_in; }
};

/*!
 *  Produces a single resource of the given type \a In
 */
template <class In>
class ProduceSingleResource : public sgl::ResourceProducerIface<In>
{
    void convertImpl()
    {
        sgl::ResourceProducerIface<In>::in()++;
    }

public:
    ProduceSingleResource(In& io_in) :
        sgl::ResourceProducerIface<In>(io_in)
    {}
    virtual ~ProduceSingleResource() {}
};

/*!
 *  Produces \a i_resourceToProduce resources of the given type \a In
 */
template <class In>
class ProduceResources : public sgl::ResourceProducerIface<In>
{
    int m_resourceToProduce;

    void convertImpl()
    {
        sgl::ResourceProducerIface<In>::in().increment(m_resourceToProduce);
    }

public:
    ProduceResources(int i_resourcesToProduce, In& io_in) :
        sgl::ResourceProducerIface<In>(io_in),
        m_resourceToProduce(i_resourcesToProduce)
    {}
    virtual ~ProduceResources() {}
};

}   // namespace sgl

#endif // RESOURCEPRODUCER_H
