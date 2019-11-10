#include "resource.h"

Resource::Resource(int store, int monthly)
{
    _store = store;
    _monthly = monthly;

    _display_store = QString();
    _display_monthly = QString();

    _max = DEFAULT_MAX;
}

int Resource::getStore()
{
    return _store;
}

int Resource::getMonthly()
{
    return _monthly;
}

QString Resource::displayStore()
{
    return Reference::displayNumberWithUnit(_store);
}

QString Resource::displayMonthly()
{
    QString neg = _monthly > 0 ? QString("+") : QString("-");
    QString display_number = Reference::displayNumberWithUnit(abs(_monthly));
    return neg + display_number;
}

void Resource::storeAdd(int number)
{
    _store += number;
    if(_store > DEFAULT_MAX)
        _store = DEFAULT_MAX;
}

void Resource::storeSub(int number)
{
    _store -= number;
    if(_store < 0)
        _store = 0;
}

void Resource::monthlyAdd(int number)
{
    _monthly += number;
}

void Resource::monthlySub(int number)
{
    _monthly -= number;
}

