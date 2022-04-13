#ifndef RESOURCEDRAWER_H
#define RESOURCEDRAWER_H

#include "resource.h"
#include <QDebug>

namespace sgl {

/*!
 * \brief The ResourceViewIface class
 *  interface to the resource view used as a base class to display / render the resource objects
 *  the interface implements a NVI (non virtual interface)
 */
class ResourceViewIface
{
    virtual void drawImpl() const = 0;

    sgl::GenericResourceShPtr m_resourcePtr;

public:
    ResourceViewIface(const sgl::GenericResourceShPtr& theResourceToDrawPtr);
    virtual ~ResourceViewIface();

    void draw() const { drawImpl(); }
    inline const sgl::GenericResourceShPtr resourcePtr() const { return m_resourcePtr; }
};

/*!
 * \brief The ResourceViewTerminal class
 *  draw (i.e. print) the resource to stdout
 */
class ResourceViewTerminal : public sgl::ResourceViewIface
{
    virtual void drawImpl() const
    {
        qDebug() << QString("--[%1]-[%2]--")
                    .arg(resourcePtr()->name())
                    .arg(resourcePtr()->value());
    }

public:
    ResourceViewTerminal(const sgl::GenericResourceShPtr& theResourceToDraw);
    virtual ~ResourceViewTerminal();
};

}   // namespace sgl

#endif // RESOURCEDRAWER_H
