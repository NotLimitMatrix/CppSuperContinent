#include "Reference.h"

QString Reference::displayNumberWithUnit(int number)
{
    if(number<0)
        exit(0);
    else if (number > 1000000000)
        return  QString("1G");
    else if(number > 999999)
        return  QString::number(number / 1000000, 10) + "M";
    else if(number > 999)
        return  QString::number(number / 1000, 10) + "K";
    else
        return  QString::number(number, 10);
}
