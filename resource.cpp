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

void Resource::storeUpdate(int number)
{
    _store += number;
    if(_store > _max)
        _store = _max;
    if(_store < 0)
        _store = 0;
}

void Resource::monthlyUpdate(int number)
{
    _monthly += number;
}

