#ifndef FUNCTION_H
#define FUNCTION_H

#include<QString>

static QString displayNumber(int number)
{
    if(number > 100000000)
        return "1G";

    if(number < 0)
        return "-"+displayNumber(-number);

    if(number<1000)
        return QString::number(number);
    else if(number > 1000 && number < 1000000)
        return QString::number(number/1000) + "K";
    else if(number > 1000000 && number < 1000000000)
        return QString::number(number/1000000) + "M";
    else
        return "1G";
}

#endif // FUNCTION_H
