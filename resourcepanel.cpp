#include "resourcepanel.h"



ResourcePanel::ResourcePanel(Resource *e, Resource *m, Resource *f, Resource *c, Resource *a)
{
    //qRegisterMetaType<ResourcePanel>("ResourcePanel");
    energy = e;
    mineral = m;
    food = f;
    consumerGoods = c;
    alloys = a;
}

Resource* ResourcePanel::getFood()
{
    return food;
}

Resource* ResourcePanel::getEnergy()
{
    return energy;
}

Resource* ResourcePanel::getMineral()
{
    return mineral;
}

Resource* ResourcePanel::getConsumerGoods()
{
    return consumerGoods;
}

Resource* ResourcePanel::getAlloys()
{
    return alloys;
}
