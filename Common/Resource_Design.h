#ifndef RESOURCE_DESIGN_H
#define RESOURCE_DESIGN_H

#include "Resource.h"

const QString KEY_TIME("time");
const QString KEY_ENERGY("energy");
const QString KEY_MINERAL("mineral");
const QString KEY_FOOD("food");
const QString KEY_CONSUMER_GOODS("consumer_goods");
const QString KEY_ALLOY("alloy");
const QString KEY_TECHNOLOGY_POINT("technology_point");

const Resource Time(KEY_TIME, NULL);
const Resource Energy(KEY_ENERGY, NULL);
const Resource Mineral(KEY_MINERAL, NULL);
const Resource Food(KEY_FOOD, NULL);
const Resource ConsumerGoods(KEY_CONSUMER_GOODS, KEY_MINERAL, 2);
const Resource Alloy(KEY_ALLOY, KEY_MINERAL, 4);
const Resource TechnologyPoint(KEY_TECHNOLOGY_POINT, KEY_CONSUMER_GOODS);

#endif // RESOURCE_DESIGN_H
