#include "resource.h"

sgl::GenericResource::GenericResource(const GenericResource& m_rhs) :
    m_range(m_rhs.m_range),
    m_value(m_rhs.m_value),
    m_initialValue(m_rhs.m_initialValue),
    m_name(m_rhs.m_name)
{}

sgl::GenericResource& sgl::GenericResource::operator=(const GenericResource& i_rhs)
{
    if(this != &i_rhs) {
        this->m_range = i_rhs.m_range;
        this->m_value = i_rhs.m_value;
        this->m_initialValue = i_rhs.m_initialValue;
        this->m_name = i_rhs.m_name;
    }
    return *this;
}

void sgl::GenericResource::value(int i_newValue)
{
    if( m_range.contains(i_newValue) ) {
        m_value = i_newValue;
    }
    else {
        throw sgl::resource::ValueOutOfRange();
    }
}
