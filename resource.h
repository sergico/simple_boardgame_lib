#ifndef RESOURCE_H
#define RESOURCE_H

#include <QString>
#include <exception>
#include <QSharedPointer>

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
    int m_initialValue;
    QString m_name;

public:
    GenericResource(sgl::Range<int> i_range,
             int i_startingValue,
             const QString& i_resourceName) :
        m_range(i_range),
        m_value(i_startingValue),
        m_initialValue(i_startingValue),
        m_name(i_resourceName)
    {
        if( !m_range.contains(m_value) ) {
            throw sgl::resource::InitialValueOutOfRange();
        }
        if( i_resourceName.isEmpty() ) {
            throw sgl::resource::EmptyResourceName();
        }
    }
    virtual ~GenericResource() {}

    GenericResource(const GenericResource& m_rhs);
    GenericResource& operator=(const GenericResource& i_rhs);

    inline int value() const { return m_value; }
    void value(int i_newValue);

    inline int initialValue() const { return m_initialValue; }
    inline const QString name() const { return m_name; }

    inline int increment(int i_value) {
        if(m_range.contains(m_value+i_value)) {
            m_value += i_value;
            return i_value;
        }
        else {
            throw sgl::resource::ValueOutOfRange();
        }

    }

    inline int decrement(int i_value) {
        return increment(-i_value);
    }

    inline int operator++(int) {
        this->increment(1);
        return m_value;
    }

    inline int operator--(int) {
        this->decrement(1);
        return m_value;
    }

    inline const QString toString() const {
        return QString("%1:%2").arg(m_name).arg(m_value);
    }

};

typedef QSharedPointer<sgl::GenericResource> GenericResourceShPtr;

}   // namespace sgl

#endif // RESOURCE_H



