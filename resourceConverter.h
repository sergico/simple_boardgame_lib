#ifndef RESOURCECONVERTER_H
#define RESOURCECONVERTER_H

namespace sgl {

template<class In, class Out>
class ResourceConverterIface
{
    virtual void convertImpl() = 0;

//protected:
    In& m_in;
    Out& m_out;

public:
    ResourceConverterIface(In& io_in, Out& io_out) :
        m_in(io_in),
        m_out(io_out)
    {}
    virtual ~ResourceConverterIface() {}

    void convert() { convertImpl(); }

    inline In& in() const { return m_in; }
    inline Out& out() const { return m_out; }
};

/*!
 *  Convert Resources
 */
template <class In, class Out>
class ConvertResources : public sgl::ResourceConverterIface<In, Out>
{
    int m_inResourceToConsume;
    int m_outResourceToProduce;

    void convertImpl()
    {
        /*
         *  ADD ERROR HANDLING ?
         */
        sgl::ResourceConverterIface<In, Out>::m_in.decrement(m_inResourceToConsume);
        sgl::ResourceConverterIface<In, Out>::m_out.increment(m_outResourceToProduce);
    }

public:
    ConvertResources(int i_inResourceToConsume, In& io_in,
                     int i_outResourcesToProduce, Out& io_out) :
        sgl::ResourceConverterIface<In, Out>(io_in, io_out),
        m_inResourceToConsume(i_inResourceToConsume),
        m_outResourceToProduce(i_outResourcesToProduce)
    {}
    virtual ~ConvertResources() {}
};


}   // namespace sgl

#endif // RESOURCECONVERTER_H
