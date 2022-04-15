#ifndef RESOURCECONVERTER_H
#define RESOURCECONVERTER_H

#include "resource.h"

namespace sgl {

class ResourceConverterIface
{
    virtual void convertImpl() = 0;

    sgl::GenericResourceShPtr m_inResource;
    sgl::GenericResourceShPtr m_outResource;

public:
    ResourceConverterIface(sgl::GenericResourceShPtr& io_inResourceShPtr,
                           sgl::GenericResourceShPtr& io_outResourceShPtr) :
        m_inResource(io_inResourceShPtr),
        m_outResource(io_outResourceShPtr)
    {}
    virtual ~ResourceConverterIface() {}

    void convert();

    inline sgl::GenericResourceShPtr inResourcePtr() const { return m_inResource; }
    inline sgl::GenericResourceShPtr outResourcePtr() const { return m_outResource; }
};

/*!
 *  Convert Resources
 */
class SimpleResourceConverter : public sgl::ResourceConverterIface
{
    void convertImpl()
    {
        int _v = inResourcePtr()->decrement(inResourcePtr()->value());
        outResourcePtr()->increment(_v);
    }

public:
    SimpleResourceConverter(sgl::GenericResourceShPtr& io_inShPtr,
                            sgl::GenericResourceShPtr& io_outShPtr) :
        sgl::ResourceConverterIface(io_inShPtr, io_outShPtr)
    {}
    virtual ~SimpleResourceConverter() {}
};


}   // namespace sgl

#endif // RESOURCECONVERTER_H
