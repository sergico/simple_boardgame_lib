#include "resource.h"

void sgl::GenericResource::value(int i_newValue)
{
    if( m_range.contains(i_newValue) ) {
        m_value = i_newValue;
    }
    else {
        throw sgl::resource::ValueOutOfRange();
    }
}
