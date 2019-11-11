#ifndef RESOURCEPANEL_H
#define RESOURCEPANEL_H

#include "resource.h"

class ResourcePanel
{
private:
    Resource *energy;
    Resource *mineral;
    Resource *food;
    Resource *consumerGoods;
    Resource *alloys;
public:
    ResourcePanel(Resource *e, Resource *m, Resource *f, Resource *c, Resource *a);

    Resource* getFood();
    Resource* getMineral();
    Resource* getEnergy();
    Resource* getConsumerGoods();
    Resource* getAlloys();
};

#endif // RESOURCEPANEL_H
/*    energy = Resource(0,0);
    mineral = Resource(0,0);
    food = Resource(0,0);
    consumerGoods = Resource(0,0);
    alloys = Resource(0,0);*/
