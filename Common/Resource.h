#ifndef RESOURCE_H
#define RESOURCE_H

#include <QString>
class Resource
{
    QString name;
    QString material;
    int rate;

public:
    Resource();
    Resource(QString n, QString m, int r = 1)
    {
        name = n;
        material = m;
        rate = r;
    }
    QString getName() { return name; }
    QString getMaterial() { return material; }
};

#endif // RESOURCE_H
