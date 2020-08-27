#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H
#include <QString>

enum { MILITARY, CIVIAL, BEYOND };

class Technology
{
    QString name;
    QString description;
    int cost;
    int area; // 军事 0、民用 1、超越 2

    bool isLoop = false;
    int loop = 1;

public:
    Technology();
};

#endif // TECHNOLOGY_H
