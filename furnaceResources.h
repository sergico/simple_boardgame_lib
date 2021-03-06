#ifndef FURNACERESOURCES_H
#define FURNACERESOURCES_H

#include <QString>
#include "resource.h"

namespace furnace {

static const int MAX_RESOURCE_VALUE = 100;

    namespace resourcename {
        const QString cog("cog");
        const QString coal("coal");
        const QString ironBar("iron bar");
        const QString oilBarrel("oil barrel");
        const QString coin("coin");
    }   // namespace resourcename

class Cog : public sgl::GenericResource
{
public:
    Cog() :
        sgl::GenericResource(sgl::Range<int>(0, MAX_RESOURCE_VALUE), 0, furnace::resourcename::cog)
    {}
};

class Coal : public sgl::GenericResource
{
public:
    Coal() :
        sgl::GenericResource(sgl::Range<int>(0, MAX_RESOURCE_VALUE), 0, furnace::resourcename::coal)
    {}
};

class IronBar : public sgl::GenericResource
{
public:
    IronBar() :
        sgl::GenericResource(sgl::Range<int>(0, MAX_RESOURCE_VALUE), 0, furnace::resourcename::ironBar)
    {}
};

class OilBarrel : public sgl::GenericResource
{
public:
    OilBarrel() :
        sgl::GenericResource(sgl::Range<int>(0, MAX_RESOURCE_VALUE), 0, furnace::resourcename::oilBarrel)
    {}
};

class Coin : public sgl::GenericResource
{
public:
    Coin() :
        sgl::GenericResource(sgl::Range<int>(0, MAX_RESOURCE_VALUE), 0, furnace::resourcename::coin)
    {}
};

}   // namespace furnace

#endif // FURNACERESOURCES_H
