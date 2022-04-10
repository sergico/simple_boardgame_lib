#ifndef RESOURCE_EXCEPTIONS_H
#define RESOURCE_EXCEPTIONS_H

#include <exception>

namespace sgl {
    namespace resource
    {

class EmptyResourceName : public std::exception
{
    virtual const char* what() const throw() {
        return "resource name is empty";
    }
};

class InitialValueOutOfRange : public std::exception
{
    virtual const char* what() const throw() {
        return "resource initial value is out of range";
    }
};


    }   // namespace resource

}



#endif // RESOURCE_EXCEPTIONS_H
