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
    void storeAdd(int number);
    void storeSub(int number);
    void monthlyAdd(int number);
    void monthlySub(int number);
};


#endif // RESOURCE_H
