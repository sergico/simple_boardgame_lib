#ifndef RANGE_H
#define RANGE_H

#include "range_exceptions.h"

namespace sgl
{

/*******************************************************************************
 *  Range
 *******************************************************************************/

/*
 *  define a value range for object of type T
 *  for T to be a valid object to used in a range
 *  T needs to support or implement the < and = operators
 */
template<class T>
class Range
{
    T m_min;
    T m_max;

public:
    Range(T i_min, T i_max) :
        m_min(i_min),
        m_max(i_max)
    {
        if( i_max < i_min ) {
            throw range::InvalidRange();
        }
    }

    T min() const { return m_min; }
    T max() const { return m_max; }

    /*!
     * \brief contains
     *  check if the given \a i_value is contained into the defined range
     *  the interval is closed, that is, the limits of the range are included
     * \param i_value [in] the value to check
     * \return true if the value is contained into teh range; false otherwise
     */
    bool contains(T i_value)
    {
        if (i_value < m_min) {
            return false;
        }
        if (m_max < i_value) {
            return false;
        }
        return true;
    }
};

}   // namespace sgl


#endif // RANGE_H
