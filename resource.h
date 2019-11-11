#ifndef RESOURCE_H
#define RESOURCE_H

#include "Reference.h"

class Resource
{
private:
    int _store;
    int _monthly;

    QString _display_store;
    QString _display_monthly;

    int _max;

public:
    Resource(int store, int monthly);

    int getStore();
    int getMonthly();
    QString displayStore();
    QString displayMonthly();
    void storeUpdate(int number);
    void monthlyUpdate(int number);
};

typedef QList<Resource*> RESOURCE_LIST;
#endif // RESOURCE_H
