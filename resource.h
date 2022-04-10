#ifndef RESOURCE_H
#define RESOURCE_H

#include <QString>
#include <exception>

#include "resource_exceptions.h"
#include "range.h"

/*
 * can a resource be negative? -> policy
 * can a resource have a max ? -> policy
 *
 * a resource have a type, i.e. coal, oil, etc
 * a resource have a name, ie. coal, streal, oil, etc
 * a resource have a value
 * a resource has a starting value (not necessarly zero)
 * a resource has a min and max value
 */
namespace sgl {

class GenericResource
{
    sgl::Range<int> m_range;
    int m_value;
    const QString m_name;

public:
    GenericResource(sgl::Range<int> i_range,
             int i_startingValue,
             const QString& i_resourceName) :
        m_range(i_range),
        m_value(i_startingValue),
        m_name(i_resourceName)
    {
        if( !m_range.contains(m_value) ) {
            throw sgl::resource::InitialValueOutOfRange();
        }
        if( i_resourceName.isEmpty() ) {
            throw sgl::resource::EmptyResourceName();
        }
    }

    inline int value() const { return m_value; }
    inline void value(int i_newValue) { m_value = i_newValue; }
    inline const QString name() const { return m_name; }

    inline int increment(int i_value) {
        if(m_range.contains(m_value+i_value)) {
            m_value += i_value;
            return i_value;
        }
        throw sgl::range::OutOfRange();
    }

    inline int decrement(int i_value) {
        return increment(-i_value);
#if (0)
        if(m_range.contains(m_value-i_value)) {
            m_value -= i_value;
            return i_value;
        }
        throw range::OutOfRange();
#endif
    }
};

}   // namespace sgl

#endif // RESOURCE_H



