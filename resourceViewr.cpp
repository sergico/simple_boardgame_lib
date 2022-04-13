#include "resourceViewr.h"

using namespace sgl;

ResourceViewIface::ResourceViewIface(const sgl::GenericResourceShPtr &theResourceToDrawPtr) :
    m_resourcePtr(theResourceToDrawPtr)
{}

ResourceViewIface::~ResourceViewIface() {}

ResourceViewTerminal::ResourceViewTerminal(const sgl::GenericResourceShPtr& theResourceToDraw) :
    sgl::ResourceViewIface(theResourceToDraw)
{}

ResourceViewTerminal::~ResourceViewTerminal() {}
