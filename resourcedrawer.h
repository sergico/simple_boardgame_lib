#ifndef RESOURCEDRAWER_H
#define RESOURCEDRAWER_H

#include "resource.h"
#include <QDebug>

namespace sgl {


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
