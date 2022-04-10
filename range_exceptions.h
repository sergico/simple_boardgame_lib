#ifndef RANGE_EXCEPTIONS_H
#define RANGE_EXCEPTIONS_H

#include <exception>

namespace sgl {
    namespace range
    {

class OutOfRange : public std::exception
{
    virtual const char* what() const throw() {
        return "value is out of range";
    }
};

class InvalidRange : public std::exception
{
    virtual const char* what() const throw() {
        return "invalid range";
    }
};

    }   // namespace range

}


#endif // RANGE_EXCEPTIONS_H
