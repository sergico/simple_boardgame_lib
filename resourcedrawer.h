#ifndef RESOURCEDRAWER_H
#define RESOURCEDRAWER_H

#include "resource.h"
#include <QDebug>

namespace sgl {


class ResourceViewIface
{
    virtual void drawImpl() const = 0;

protected:
    sgl::GenericResourceShPtr m_resourcePtr;

public:
    ResourceViewIface(const sgl::GenericResourceShPtr& theResourceToDrawPtr);
    virtual ~ResourceViewIface();

    void draw() const { drawImpl(); }
};

class ResourceViewTerminal : public sgl::ResourceViewIface
{
    virtual void drawImpl() const
    {
        qDebug() << QString("--[%1]-[%2]--")
                    .arg(m_resourcePtr->name())
                    .arg(m_resourcePtr->value());
    }

public:
    ResourceViewTerminal(const sgl::GenericResourceShPtr& theResourceToDraw);
    virtual ~ResourceViewTerminal();
};

}   // namespace sgl

#endif // RESOURCEDRAWER_H
